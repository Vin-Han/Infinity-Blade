// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/UI/LoginUserWidget.h"
#include"Engine/World.h"
#include"TimerManager.h"
#include"Engine/Engine.h"
#include"Kismet/GameplayStatics.h"

bool ULoginUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	BackBtn		= Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	LoginBtn	= Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));

	LoginBtn->OnClicked.AddDynamic(this,&ULoginUserWidget::LoginBtnClickOnEvent);

	NickNameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_NickName")));
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));

	Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("LoadingCir")));

	MessageUI = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageWidget")));

	return true;
}

void ULoginUserWidget::LoginBtnClickOnEvent()
{
	LoginBtn->SetIsEnabled(false);

	FString Nickname = NickNameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();
	FString WrongReason = "Login Successfully";

	Loading->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetTimerManager().SetTimer(TH_LoadingCircular, this, &ULoginUserWidget::HideCircular, 1, false, 0.3f);
	if(!CheckInputSuitable(Nickname,Password,WrongReason))
		MessageUI->ShowMessageOnScreen(WrongReason);
	else{
		UCustomGameInstance* GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());
		GameInstance->LoadNewPlayer(Nickname,"0");
		UGameplayStatics::OpenLevel(GetWorld(),TEXT("/Game/Map/Map_Main.Map_Main'"));
	}
	
}

bool ULoginUserWidget::CheckInputSuitable(FString& NickName, FString& Password, FString& WrongReason)
{
	if (NickName.Len() < 2 || NickName.Len() > 6) {
		WrongReason = "NickName not right!";
		return false;
	}
	if (Password.Len() != 6) {
		WrongReason = "Password not suitable!";
		return false;
	}
	return true;
}

void ULoginUserWidget::HideCircular()
{
	Loading->SetVisibility(ESlateVisibility::Hidden);
	LoginBtn->SetIsEnabled(true);
}
