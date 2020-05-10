// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CircularThrobber.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "LoadUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoadUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    UPROPERTY()
        UTextBlock* TextContinue;
    UPROPERTY()
        UTextBlock* TextLoading;
    UPROPERTY()
        UCircularThrobber* Loading;

public:
    virtual bool Initialize() override;
};
