// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "XBlade.generated.h"

UCLASS()
class INFINITYBLADE_API AXBlade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AXBlade();
	UPROPERTY(VisibleAnyWhere)
		UParticleSystemComponent* Particle;
	UPROPERTY(VisibleAnyWhere)
		UCapsuleComponent* CollosionCom;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
