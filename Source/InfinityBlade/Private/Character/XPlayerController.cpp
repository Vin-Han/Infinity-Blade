// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Character/XPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "UI/ItemUserWidget.h"
#include "Kismet/KismetMathLibrary.h"

void AXPlayerController::BeginPlay()
{
	Super::BeginPlay();
	InitXPlayer();
	InitXUI();

	IceStone_CD = 5;
	IceStone_Cur = 0;

	Cure_CD = 8;
	Cure_Cur = 0;

	Thunder_CD = 12;
	Thunder_Cur = 0;
}

void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
	InputComponent->BindAxis("TurnHead", this, &AXPlayerController::TurnHead);
}

void AXPlayerController::MoveForward(float speed){
	FRotator Rotation = XCharacter->GetActorRotation();
	FRotator YawRotator = FRotator(0.f,Rotation.Yaw,0.f);

	FVector Direction =  FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
	XCharacter->AddMovementInput(Direction,speed,false);
}

void AXPlayerController::MoveRight(float speed){
	FRotator Rotation = XCharacter->GetActorRotation();
	FRotator YawRotator = FRotator(0.f, Rotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
	XCharacter->AddMovementInput(Direction, speed*0.1, false);
}

void AXPlayerController::TurnHead(float speed)
{
	FRotator Rotation = GetControlRotation();
	FRotator YawRotator = FRotator(0.f, Rotation.Yaw, 0.f);

	FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
	XCharacter->AddMovementInput(Direction, 0, false);
}

void AXPlayerController::LockAI()
{
	FVector Location = XCharacter->GetActorLocation();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAICharacter::StaticClass(), AIArray);
	int AINum = AIArray.Num();
	if (AINum > 0) {
		float MinDis = FVector::Dist(Location, AIArray[0]->GetActorLocation());
		AActor* MinActor = AIArray[0];
		for (int i = 0; i < AINum; i++){
			if (Cast<AAICharacter>(AIArray[i])->bIsDead) continue;
			float TpDis = FVector::Dist(Location, AIArray[i]->GetActorLocation());
			if (MinDis > TpDis) {
				MinDis = TpDis;
				MinActor = AIArray[i];
			}
		}

		if (MinDis <= 200){
			FRotator Rotation = XCharacter->GetCapsuleComponent()->GetComponentRotation();
			Rotation.Yaw= (UKismetMathLibrary::FindLookAtRotation(Location, MinActor->GetActorLocation())).Yaw;
			XCharacter->GetCapsuleComponent()->SetRelativeRotation(Rotation);
		}
	}

}

void AXPlayerController::UpDateProgressBar(float HPC, float MPC)
{
	
	if (PlayerState)
	{
		if (MPC != 0)
		{
			XPlayerState->SetCurMP(XPlayerState->GetCurMP() - MPC);
			if (XPlayerState->GetCurMP() <= 0)
				XPlayerState->SetCurMP(0);
			else if (XPlayerState->GetCurMP() >= XCharacter->TotalMP)
				XPlayerState->SetCurMP(XCharacter->TotalMP);

			MainWidget->ProgressBar_MP->SetPercent(1 - XPlayerState->GetCurMP() / XCharacter->TotalMP);
		}
		if (HPC != 0)
		{
			XPlayerState->SetCurHP(XPlayerState->GetCurHP() - HPC);

			if(XPlayerState->GetCurHP() >=  XCharacter->TotalHP)
				XPlayerState->SetCurHP(XCharacter->TotalHP);
			else if (XPlayerState->GetCurHP() <= 0)
				XPlayerState->SetCurHP(0);

			MainWidget->ProgressBar_HP->SetPercent(1 - XPlayerState->GetCurHP() / XCharacter->TotalHP);
		}
	}
	
}

void AXPlayerController::AttackBtnClickOnEvent()
{
	if (XAnimInstance->bIsPlaying) return;
	LockAI();
	UAnimMontage* CurAtkMontage = XCharacter->AtkMontage;
 	FName CurSec =  XAnimInstance->Montage_GetCurrentSection(CurAtkMontage);
	if (CurSec.IsNone())
		XAnimInstance->Montage_Play(CurAtkMontage);
	else if (CurSec.IsEqual(FName("1 Attack")) && XAnimInstance->bIsAble2)
		XAnimInstance->Montage_JumpToSection(FName("2 Attack"), CurAtkMontage);
	else if (CurSec.IsEqual(FName("2 Attack")) && XAnimInstance->bIsAble2)
		XAnimInstance->Montage_JumpToSection(FName("3 Attack"), CurAtkMontage);
	else if (CurSec.IsEqual(FName("3 Attack")) && XAnimInstance->bIsAble2)
		XAnimInstance->Montage_JumpToSection(FName("4 Attack"), CurAtkMontage);
	else if (CurSec.IsEqual(FName("4 Attack")) && XAnimInstance->bIsAble2)
		XAnimInstance->Montage_JumpToSection(FName("5 Attack"), CurAtkMontage);
}

void AXPlayerController::IceStoneBtnClickOnEvent()
{
	if (XAnimInstance->bIsPlaying) return;
	LockAI();
	if (XPlayerState->GetCurMP() > 10)
	{
		XAnimInstance->Montage_Play(XCharacter->IceStoneMontage, 1.f);
		XCharacter->GetWorldTimerManager().SetTimer(TH_IceStone, this, &AXPlayerController::IceStoneCallBack, 0.1, true);
		IceStone_Cur = IceStone_CD;
	}
}

void AXPlayerController::IceStoneCallBack()
{
	if (IceStone_Cur <= 0)
	{
		MainWidget->Button_IceStone->bIsEnabled = true;
		MainWidget->Bar_IceStone->SetVisibility(ESlateVisibility::Hidden);
		MainWidget->Text_IceStone->SetVisibility(ESlateVisibility::Hidden);
		XCharacter->GetWorldTimerManager().ClearTimer(TH_IceStone);
	}
	else
	{
		MainWidget->Button_IceStone->bIsEnabled = false;
		MainWidget->Bar_IceStone->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Text_IceStone->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Bar_IceStone->SetPercent(IceStone_Cur / IceStone_CD);
		MainWidget->Text_IceStone->SetText(FText::FromString(FString::FromInt((IceStone_Cur)) + "s"));
		IceStone_Cur = IceStone_Cur - 0.1;
	}
}

void AXPlayerController::CureBtnClickOnEvent()
{
	if (XAnimInstance->bIsPlaying) return;
	if (XPlayerState->GetCurMP() > 10)
	{
		XAnimInstance->Montage_Play(XCharacter->CureMontage, 1.f);
		XCharacter->GetWorldTimerManager().SetTimer(TH_Cure, this, &AXPlayerController::CureCallBack, 0.1, true);
		Cure_Cur = Cure_CD;
	}
}

void AXPlayerController::CureCallBack()
{
	if (Cure_Cur <= 0)
	{
		MainWidget->Button_Cure->bIsEnabled = true;
		MainWidget->Bar_Cure->SetVisibility(ESlateVisibility::Hidden);
		MainWidget->Text_Cure->SetVisibility(ESlateVisibility::Hidden);
		XCharacter->GetWorldTimerManager().ClearTimer(TH_Cure);
	}
	else
	{
		MainWidget->Button_Cure->bIsEnabled = false;
		MainWidget->Bar_Cure->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Text_Cure->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Bar_Cure->SetPercent(Cure_Cur / Cure_CD);
		MainWidget->Text_Cure->SetText(FText::FromString(FString::FromInt((Cure_Cur)) + "s"));
		Cure_Cur = Cure_Cur - 0.1;
	}
}

void AXPlayerController::ThunderBtnClickOnEvent()
{
	if (XAnimInstance->bIsPlaying) return;
	if (XPlayerState->GetCurMP() > 20)
	{
		XAnimInstance->Montage_Play(XCharacter->ThunderMontage, 1.f);
		XCharacter->GetWorldTimerManager().SetTimer(TH_Thunder, this, &AXPlayerController::ThunderCallBack, 0.1, true);
		Thunder_Cur = Thunder_CD;
	}
}

void AXPlayerController::ThunderCallBack()
{
	if (Thunder_Cur <= 0)
	{
		MainWidget->Button_Thunder->bIsEnabled = true;
		MainWidget->Bar_Thunder->SetVisibility(ESlateVisibility::Hidden);
		MainWidget->Text_Thunder->SetVisibility(ESlateVisibility::Hidden);
		XCharacter->GetWorldTimerManager().ClearTimer(TH_Thunder);
	}
	else
	{
		MainWidget->Button_Thunder->bIsEnabled = false;
		MainWidget->Bar_Thunder->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Text_Thunder->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Bar_Thunder->SetPercent(Thunder_Cur / Thunder_CD);
		MainWidget->Text_Thunder->SetText(FText::FromString(FString::FromInt((Thunder_Cur)) + "s"));
		Thunder_Cur = Thunder_Cur - 0.1;
	}
}

void AXPlayerController::XBladeBtnClickOnEvent()
{
	if (XAnimInstance->bIsPlaying) return;
	if (XCharacter->bIsXBlade == false) {
		XAnimInstance->Montage_Play(XCharacter->XBladeMontage, 1.f);
		MainWidget->Button_XBlade->bIsEnabled = false;
		MainWidget->Image_Cover->SetVisibility(ESlateVisibility::Visible);
		MainWidget->Image_XBlade->SetOpacity(0.3);
	}
}

void AXPlayerController::InitXPlayer()
{
	XCharacter = Cast<AXCharacter>(GetPawn());
	if (XCharacter->XWeaponClass) {
		XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
		XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		XWeapon->CapsuleCom->OnComponentBeginOverlap.AddDynamic(this,&AXPlayerController::WeaponOverlapDamage);
	}

	XPlayerState = Cast<AXPlayerState>(this->PlayerState);
	if (XPlayerState) {
		InitXState();
	}
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());
	if (XAnimInstance) { 
		XAnimInstance->NormalAtk = XCharacter->NormalAtk; 
		XAnimInstance->PlayerState = XPlayerState;
		XAnimInstance->bIsAtking = false;
	}
}

void AXPlayerController::InitXState()
{
	XPlayerState->SetCurHP(XCharacter->TotalHP * 0.6);
	XPlayerState->SetCurMP(XCharacter->TotalMP * 0.6);
	XPlayerState->SetAtkDmg(XCharacter->NormalAtk);
}

void AXPlayerController::InitXUI()
{
	MainWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/UI/BP_MainUserWidget.BP_MainUserWidget_C'")));
	if (MainWidget) MainWidget->AddToViewport();

	if (MainWidget->Button_Package)	MainWidget->Button_Package->OnClicked.AddDynamic(this, &AXPlayerController::BagBtnClickOnEvent);
	if (MainWidget->Button_Attack)	MainWidget->Button_Attack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnClickOnEvent);
	if (MainWidget->Button_IceStone)MainWidget->Button_IceStone->OnClicked.AddDynamic(this, &AXPlayerController::IceStoneBtnClickOnEvent);
	if (MainWidget->Button_Cure)	MainWidget->Button_Cure->OnClicked.AddDynamic(this, &AXPlayerController::CureBtnClickOnEvent);
	if (MainWidget->Button_Thunder)	MainWidget->Button_Thunder->OnClicked.AddDynamic(this, &AXPlayerController::ThunderBtnClickOnEvent);
	if (MainWidget->Button_XBlade)	MainWidget->Button_XBlade->OnClicked.AddDynamic(this, &AXPlayerController::XBladeBtnClickOnEvent);

	if (MainWidget->ProgressBar_HP)	MainWidget->ProgressBar_HP->SetPercent(1-XPlayerState->GetCurHP()/XCharacter->TotalHP);
	if (MainWidget->ProgressBar_MP)	MainWidget->ProgressBar_MP->SetPercent(1-XPlayerState->GetCurMP() / XCharacter->TotalMP);

	BagWidget = CreateWidget<UCharacterUserWidget>(GetGameInstance(), LoadClass<UCharacterUserWidget>(nullptr, TEXT("WidgetBlueprint'/Game/UI/BP_CharacterWidget.BP_CharacterWidget_c'")));
	if (BagWidget->Button_Close)	BagWidget->Button_Close->OnClicked.AddDynamic(this, &AXPlayerController::BagCloseBtnClickOnEvent);
}

void AXPlayerController::WeaponOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult)
{
	if (XAnimInstance && XAnimInstance->bIsAtking) {
		UGameplayStatics::ApplyDamage(OtherActor,XPlayerState->GetAtkDmg(),this,XCharacter,nullptr);
	}
}

void AXPlayerController::BagBtnClickOnEvent()
{
	BagWidget->ScrollBox_List->ClearChildren();

	for (int i = 0; i < XCharacter->ItemList.Num(); i++){
		FPickupInfo Temp = XCharacter->ItemList[i];
		UItemUserWidget* Item = CreateWidget<UItemUserWidget>(GetGameInstance(),LoadClass<UItemUserWidget>(nullptr,TEXT("WidgetBlueprint'/Game/UI/BP_SingleItem.BP_SingleItem_c'")));
		Item->pID = Temp.ID;
		Item->TextBlock_Name->SetText(Temp.Name);
		Item->TextBlock_Expression->SetText(Temp.Discribe);
		Item->Image_Item->SetBrushFromTexture(Temp.Picture);
		Item->InforType = Temp.Type;
		Item->Player = XCharacter;
		Item->HPEffect = Temp.HPEffect;
		Item->MPEffect = Temp.MPEffect;
		BagWidget->ScrollBox_List->AddChild(Item);
	}

	UGameplayStatics::SetGamePaused(this, true);
	BagWidget->AddToViewport();
}

void AXPlayerController::BagCloseBtnClickOnEvent()
{
	UGameplayStatics::SetGamePaused(this, false);
	BagWidget->RemoveFromViewport();
}
