// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()

private:
	float AtkDmg;
	float CurHP;
	float CurMP;

public:


	FORCEINLINE float GetAtkDmg() { return AtkDmg; }
	FORCEINLINE void SetAtkDmg(float newatk) { AtkDmg = newatk; }

	FORCEINLINE float GetCurHP() { return CurHP; }
	FORCEINLINE void SetCurHP(float hp) { CurHP = hp; }

	FORCEINLINE float GetCurMP() { return CurMP; }
	FORCEINLINE void SetCurMP(float mp) { CurMP = mp; }
};
