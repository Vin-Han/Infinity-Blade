// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "MainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	/**/
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Rank;
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Package;
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Setting;
	/**/
	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Attack;

	UPROPERTY(Meta = (BindWidget))
		UButton* Button_IceStone;
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Bar_IceStone;
	UPROPERTY(Meta = (BindWidget))
		UTextBlock* Text_IceStone;

	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Cure;
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Bar_Cure;
	UPROPERTY(Meta = (BindWidget))
		UTextBlock* Text_Cure;

	UPROPERTY(Meta = (BindWidget))
		UButton* Button_Thunder;
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* Bar_Thunder;
	UPROPERTY(Meta = (BindWidget))
		UTextBlock* Text_Thunder;

	UPROPERTY(Meta = (BindWidget))
		UButton* Button_XBlade;
	UPROPERTY(Meta = (BindWidget))
		UImage* Image_XBlade;
	UPROPERTY(Meta = (BindWidget))
		UImage* Image_Cover;
	/**/
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_HP;
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_MP;
};
