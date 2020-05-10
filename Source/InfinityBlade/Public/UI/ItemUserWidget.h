// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Character/XCharacter.h"
#include "Pickup/ItemInfor.h"
#include "ItemUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UItemUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    /**/
    UPROPERTY()
        AXCharacter* Player;
    UPROPERTY()
        uint8 pID;
    EPIckupInfoType InforType;
    UPROPERTY()
        float HPEffect;
    UPROPERTY()
        float MPEffect;
    /**/
    UPROPERTY(Meta = (BindWidget))
        UButton* Button_Use;
    UPROPERTY(Meta = (BindWidget))
        UButton* Button_Drop;
    /**/
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_Name;
    UPROPERTY(Meta = (BindWidget))
        UTextBlock* TextBlock_Expression;
    /**/
    UPROPERTY(Meta = (BindWidget))
        UImage* Image_Item;
public:
    virtual bool Initialize() override;

    UFUNCTION()
        void UseBtnClickOnEvent();

};
