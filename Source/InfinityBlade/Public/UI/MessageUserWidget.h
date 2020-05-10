// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include"Components/TextBlock.h"
#include"Components/Button.h"
#include "MessageUserWidget.generated.h"

/**
 * Message Information UI
 */
UCLASS()
class INFINITYBLADE_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

    UPROPERTY()
        UButton* CloseBtn;

    UPROPERTY()
        UTextBlock* MessageBlock;

public:
    virtual bool Initialize() override;

    UFUNCTION()
        void CloseBtnClickOnEvent();

    void ShowMessageOnScreen(FString Message);
};