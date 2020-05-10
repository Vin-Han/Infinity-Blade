// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/UI/RegisterUserWidget.h"
#include"Engine/Engine.h"
#include"Kismet/KismetSystemLibrary.h"
#include"Engine/World.h"
#include"TimerManager.h"


bool URegisterUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	BackBtn		= Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));

	NickNameInput	= Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_NickName")));
	PasswordInput	= Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_RePassword")));

	RegisterBtn->OnClicked.AddDynamic(this,&URegisterUserWidget::RegisterBtnClickOnEvent);

	Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("Image_Loading")));

	MessageUI = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageWidget")));

	return true;
}

void URegisterUserWidget::RegisterBtnClickOnEvent(){
	RegisterBtn->SetIsEnabled(false);
	FString NickName	= NickNameInput->GetText().ToString();
	FString Password	= PasswordInput->GetText().ToString();
	FString Repassword	= RePasswordInput->GetText().ToString();
	FString WrongReason = "Successfully registered";
	Loading->SetVisibility(ESlateVisibility::Visible);
	CheckInputSuitable(NickName, Password, Repassword, WrongReason);
	MessageUI->ShowMessageOnScreen(WrongReason);
	GetWorld()->GetTimerManager().SetTimer(TH_LateHide,this,&URegisterUserWidget::HideCircular,1,false,0.3f) ;
}

bool URegisterUserWidget::CheckInputSuitable(FString& NickName, FString& Password, FString& RePassword, FString& WrongReason){

	if (NickName.Len() < 2 || NickName.Len() > 6){
		WrongReason = "NickName too long!";
		return false;
	}
	if (Password.Len() != 6) {
		WrongReason = "Password not suitable!";
		return false;
	}
	if (Password != RePassword) {
		WrongReason = "Password not same!";
		return false;
	}
	return true;
}

void URegisterUserWidget::HideCircular(){
	Loading->SetVisibility(ESlateVisibility::Hidden);
	RegisterBtn->SetIsEnabled(true);
}
