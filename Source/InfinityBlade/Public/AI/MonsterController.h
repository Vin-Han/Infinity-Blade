// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIAnimInstance.h"
#include "AICharacter.h"
#include "Weapon/Weapon.h"
#include "MonsterController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AMonsterController : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTree;
	UPROPERTY()
		UBlackboardComponent* BlackBoardCom;

	UPROPERTY()
		AWeapon* AIWeapon;
	UPROPERTY()
		AAICharacter* Monster;
	UPROPERTY()
		UAIAnimInstance* AnimInstance;
public:
	AMonsterController();

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult);

};
