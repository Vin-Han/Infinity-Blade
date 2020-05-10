// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/GameMode/StartGameMode.h"
#include"Engine/Engine.h"

void AStartGameMode::BeginPlay() {
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Hello,StartGameMode"));

	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(),LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartUserWidget.BP_StartUserWidget_c'")) );
	StartWidget->AddToViewport();
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this,&AStartGameMode::RegisterBtnClickOnEvent) ;
	StartWidget->StartBtn->OnClicked.AddDynamic(this,&AStartGameMode::LoginBtnClickOnEvent);

	RegisterWidget = CreateWidget<URegisterUserWidget>(GetGameInstance(),LoadClass<URegisterUserWidget>(this,TEXT("WidgetBlueprint'/Game/UI/BP_RegisterUserWidget.BP_RegisterUserWidget_c'")));
	RegisterWidget->BackBtn->OnClicked.AddDynamic(this,&AStartGameMode::RegisterBackBtnClickOnEvent);

	LoginWidget = CreateWidget<ULoginUserWidget>(GetGameInstance(),LoadClass<ULoginUserWidget>(this,TEXT("WidgetBlueprint'/Game/UI/BP_LoginUserWidget.BP_LoginUserWidget_c'")));
	LoginWidget->BackBtn->OnClicked.AddDynamic(this,&AStartGameMode::LoginBackBtnClickOnEvent);
}

void AStartGameMode::RegisterBtnClickOnEvent()
{
	StartWidget->RemoveFromViewport();
	RegisterWidget->AddToViewport();
}

void AStartGameMode::LoginBtnClickOnEvent()
{
	StartWidget->RemoveFromViewport();
	LoginWidget->AddToViewport();
}

void AStartGameMode::RegisterBackBtnClickOnEvent()
{
	RegisterWidget->RemoveFromViewport();
	StartWidget->AddToViewport();
}

void AStartGameMode::LoginBackBtnClickOnEvent()
{
	LoginWidget->RemoveFromViewport();
	StartWidget->AddToViewport();
}




