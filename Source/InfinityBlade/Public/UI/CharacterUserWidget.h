// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "CharacterUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UCharacterUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(Meta = (BindWidget))
        UButton* Button_Close;
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_HP;
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_MP;
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_ATK;
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_DEF;
    UPROPERTY(Meta = (BindWidget))
        UScrollBox* ScrollBox_List;
};
