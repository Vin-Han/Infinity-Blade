// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "ItemInfor.h"
#include "Pickup.generated.h"

UCLASS()
class INFINITYBLADE_API APickup : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnyWhere)
		UCapsuleComponent* CollisionCom;
	UPROPERTY(VisibleAnyWhere)
		UStaticMeshComponent* MeshCom;
	UPROPERTY(EditAnyWhere, Category = "ItemInformation")
		FPickupInfo ItemInfor;

public:	
	// Sets default values for this actor's properties
	APickup();

public:
	UFUNCTION()
		void PickupOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult);

};
