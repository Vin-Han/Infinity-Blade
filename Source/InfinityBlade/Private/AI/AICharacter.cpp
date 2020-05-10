// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/AICharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "../public/AI/AIAnimInstance.h"
#include "Engine/Engine.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	 
	AIWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	AIWidget->SetupAttachment(GetMesh());


}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	TotalHP = 500;
	CurHP = TotalHP;
	if (AIWidget) {
		HPBar = Cast<UProgressBar>(AIWidget->GetUserWidgetObject()->GetWidgetFromName(TEXT("ProgressBar_HP")));
		if (HPBar) HPBar->SetPercent(CurHP / TotalHP);
		CurHpText = Cast<UTextBlock>(AIWidget->GetUserWidgetObject()->GetWidgetFromName(TEXT("Text_CurrentHP")));
		if (CurHpText) CurHpText->SetText(FText::FromString(FString::SanitizeFloat(CurHP)));
		TotalHpText = Cast<UTextBlock>(AIWidget->GetUserWidgetObject()->GetWidgetFromName(TEXT("Text_TotalHP")));
		if (TotalHpText) TotalHpText->SetText(FText::FromString(FString::SanitizeFloat(TotalHP)));
	}

	bIsDead = false;
}

float AAICharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (CurHP <= Damage)
		CurHP = 0;
	else CurHP -= Damage;
	HPBar->SetPercent(CurHP / TotalHP);
	if (CurHpText) CurHpText->SetText(FText::FromString(FString::SanitizeFloat(CurHP)));

	if (CurHP == 0)
		GetMesh()->GetAnimInstance()->Montage_Play(DeathMontage, 1.f);
	else GetMesh()->GetAnimInstance()->Montage_Play(DamageMontage,1.f);

	return Damage;
}


