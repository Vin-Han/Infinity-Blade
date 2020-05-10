// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "../UI/MainUserWidget.h"
#include "../UI/CharacterUserWidget.h"
#include "Character/XCharacter.h"
#include "Character/XPlayerState.h"
#include "Character/XAnimInstance.h"
#include "TimerManager.h"
#include "../AI/AICharacter.h"
#include "Weapon/Weapon.h"
#include "Character/Skill/IceStone.h"
#include "XPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	/**/
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	/**/
	UPROPERTY()
		AXCharacter* XCharacter;
	UPROPERTY()
		AXPlayerState* XPlayerState;
	UPROPERTY()
		UXAnimInstance* XAnimInstance;
	UPROPERTY()
		AWeapon* XWeapon;
	/**/
	UPROPERTY()
		UMainUserWidget* MainWidget;
	UPROPERTY()
		UCharacterUserWidget* BagWidget;
	UPROPERTY()
		TArray<AActor*> AIArray;
	/**/
	UFUNCTION()
		void MoveForward(float speed);
	UFUNCTION()
		void MoveRight(float speed);
	UFUNCTION()
		void TurnHead(float speed);


		void LockAI();
	UFUNCTION()
		void UpDateProgressBar(float HPC, float MPC);
	/**/
	UFUNCTION()
		void AttackBtnClickOnEvent();
	/**/
	UFUNCTION()
		void IceStoneBtnClickOnEvent();
	FTimerHandle TH_IceStone;
	float IceStone_CD;
	float IceStone_Cur;
	UFUNCTION()
		void IceStoneCallBack();
	/**/
	UFUNCTION()
		void CureBtnClickOnEvent();
	FTimerHandle TH_Cure;
	float Cure_CD;
	float Cure_Cur;
	UFUNCTION()
		void CureCallBack();
	/**/
	UFUNCTION()
		void ThunderBtnClickOnEvent();
	FTimerHandle TH_Thunder;
	float Thunder_CD;
	float Thunder_Cur;
	UFUNCTION()
		void ThunderCallBack();
	/**/
	UFUNCTION()
		void XBladeBtnClickOnEvent();
	/**/
	UFUNCTION()
		void InitXPlayer();
	UFUNCTION()
		void InitXState();
	UFUNCTION()
		void InitXUI();
	/**/
	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,int32 BodyIndex,bool FromSweep,const FHitResult& HitRusult);
	UFUNCTION()
		void BagBtnClickOnEvent();
	UFUNCTION()
		void BagCloseBtnClickOnEvent();
};
