// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapon.generated.h"

UCLASS()
class INFINITYBLADE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnyWhere)
		UCapsuleComponent* CapsuleCom;

	UPROPERTY(VisibleAnyWhere)
		USkeletalMeshComponent* WeaponMesh;

public:	
	// Sets default values for this actor's properties
	AWeapon();


};
