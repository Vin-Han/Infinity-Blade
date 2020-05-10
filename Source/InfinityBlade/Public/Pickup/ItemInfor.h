// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Texture2D.h"
#include "ItemInfor.generated.h"

/**
 * 
 */

UENUM(BluePrintType)
enum class EPIckupInfoType:uint8
{
    HP UMETA(Displayname = "HP"),
    MP UMETA(Displayname = "MP")
};

USTRUCT(BlueprintType)
struct FPickupInfo
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        uint8 ID;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        FText Name;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        FText Discribe;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        EPIckupInfoType Type;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        UTexture2D* Picture;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        float HPEffect;
    UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Property")
        float MPEffect;
};