// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AIAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UAIAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
    UPROPERTY(VisibleAnyWhere,BlueprintReadOnly )
        float CurSpeed;
    bool bIsPlaying;
    bool bIsStop;
public:
    UFUNCTION(BlueprintCallable)
        void UpdateSpeed();
    UFUNCTION()
        void AnimNotify_PlayStart(UAnimNotify* Notify);
    UFUNCTION()
        void AnimNotify_PlayEnd(UAnimNotify* Notify);
    UFUNCTION()
        void AnimNotify_Death(UAnimNotify* Notify);
    UFUNCTION()
        void AnimNotify_StopStart(UAnimNotify* Notify);
    UFUNCTION()
        void AnimNotify_StopEnd(UAnimNotify* Notify);
};
