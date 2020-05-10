// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "IceStone.generated.h"

UCLASS()
class INFINITYBLADE_API AIceStone : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnyWhere,Category = "Ice")
		UParticleSystemComponent* IceParticle;
	UPROPERTY(VisibleAnyWhere)
		UCapsuleComponent* CollisionCom;
	UPROPERTY(VisibleAnyWhere)
		UProjectileMovementComponent* ProjectileCom;
	UPROPERTY(EditAnyWhere, Category = "Explore")
		UParticleSystem* ExplodeParicle;
	UPROPERTY(EditAnyWhere, Category = "Sound")
		USoundBase* ExplodeSound;

	float MPCost;

public:	
	// Sets default values for this actor's properties
	AIceStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	void Shoot(FVector Direction);

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult);
};
