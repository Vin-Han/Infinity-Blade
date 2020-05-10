// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/CircularThrobber.h"
#include "MessageUserWidget.h"
#include "../CustomGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "LoginUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		UButton* BackBtn;

	UPROPERTY()
		UButton* LoginBtn;

	UPROPERTY()
		UEditableTextBox* NickNameInput;

	UPROPERTY()
		UEditableTextBox* PasswordInput;

	UPROPERTY()
		UCircularThrobber* Loading;

	UPROPERTY()
		UMessageUserWidget* MessageUI;

	FTimerHandle TH_LoadingCircular;

public:
	virtual bool Initialize() override;

	UFUNCTION()
		void LoginBtnClickOnEvent();

protected:
	bool CheckInputSuitable(FString& NickName, FString& Password, FString& WrongReason);

	void HideCircular();
};
