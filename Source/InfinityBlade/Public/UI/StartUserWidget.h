// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "StartUserWidget.generated.h"

/**
 * Game Start Interface
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
		UButton* StartBtn;

	UPROPERTY()
		UButton* RegisterBtn;

	UPROPERTY()
		UButton* QuitBtn;

public:
	//Initialize Btn components;
	virtual bool Initialize() override;

	UFUNCTION()
		void QuitBtnClickEvent();

};
