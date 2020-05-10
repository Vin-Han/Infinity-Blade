// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/UI/StartUserWidget.h"
#include"Engine/Engine.h"
#include"Kismet/KismetSystemLibrary.h"

bool UStartUserWidget::Initialize()
{
	if(!Super::Initialize())
		return false;

	StartBtn	= Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	QuitBtn		= Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	QuitBtn->OnClicked.AddDynamic(this,&UStartUserWidget::QuitBtnClickEvent) ;

	return true;
}

void UStartUserWidget::QuitBtnClickEvent()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),nullptr,EQuitPreference::Quit,true);
}
