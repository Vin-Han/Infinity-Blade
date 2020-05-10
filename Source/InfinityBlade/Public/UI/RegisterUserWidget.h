// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"MessageUserWidget.h"
#include"Components/Button.h"
#include"Components/EditableTextBox.h"
#include"Components/CircularThrobber.h"
#include "RegisterUserWidget.generated.h"

/**
 * User Register Interface
 */
UCLASS()
class INFINITYBLADE_API URegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY()
        UButton* BackBtn;
    UPROPERTY()
        UButton* RegisterBtn;
    UPROPERTY()
        UEditableTextBox* NickNameInput;
    UPROPERTY()
        UEditableTextBox* PasswordInput;
    UPROPERTY()
        UEditableTextBox* RePasswordInput;
    UPROPERTY()
        UCircularThrobber* Loading;

    UPROPERTY()
        UMessageUserWidget* MessageUI;

    FTimerHandle TH_LateHide;

public:
    virtual bool Initialize() override;

    UFUNCTION()
        void RegisterBtnClickOnEvent();

protected:

    void HideCircular();

    bool CheckInputSuitable(FString& NickName, FString& Password, FString& RePassword, FString& WrongReason);
};
