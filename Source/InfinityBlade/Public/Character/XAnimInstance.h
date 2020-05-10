// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/XCharacter.h"
#include "Character/XPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Skill/XBlade.h"
#include "Skill/IceStone.h"
#include "XAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		float Speed;

	UPROPERTY()
		AXPlayerState* PlayerState;

	void ReSetNormalAtk();

	void UpdateAtk(float AtkChange = 10);

public:
	bool bIsPlaying;
	bool bIsAble2;
	bool bIsAble3;
	bool bIsAble4;
	bool bIsAble5;

	float NormalAtk;

	bool bIsAtking;
public:
	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();

	UFUNCTION()
		void AnimNotify_PlayerStart(UAnimNotify* Notify);
	UFUNCTION()
		void AnimNotify_EndStart(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_AtkStart(UAnimNotify* Notify);
	UFUNCTION()
		void AnimNotify_AtkEnd(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_2AttackInput(UAnimNotify* Notify);
	UFUNCTION()
		void AnimNotify_3AttackInput(UAnimNotify* Notify);
	UFUNCTION()
		void AnimNotify_4AttackInput(UAnimNotify* Notify);
	UFUNCTION()
		void AnimNotify_5AttackInput(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_ResetATKStatus(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_SpawnIceStone(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_Cure(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_Thunder(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_XBlade(UAnimNotify* Notify);
};
