// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "../UI/StartUserWidget.h"
#include "../UI/RegisterUserWidget.h"
#include "../UI/LoginUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * Game Mode for Start Game
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY()
		UStartUserWidget* StartWidget;

	UPROPERTY()
		URegisterUserWidget* RegisterWidget;

	UPROPERTY()
		ULoginUserWidget* LoginWidget;

public:

	virtual void BeginPlay() override;

	UFUNCTION()
		void RegisterBtnClickOnEvent();

	UFUNCTION()
		void LoginBtnClickOnEvent();

	UFUNCTION()
		void RegisterBackBtnClickOnEvent();

	UFUNCTION()
		void LoginBackBtnClickOnEvent();

};
