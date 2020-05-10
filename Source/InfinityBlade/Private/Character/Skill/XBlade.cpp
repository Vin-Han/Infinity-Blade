// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Character/Skill/XBlade.h"

// Sets default values
AXBlade::AXBlade()
{
	CollosionCom = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));

	RootComponent = CollosionCom;
	Particle->SetupAttachment(CollosionCom);
}

// Called when the game starts or when spawned
void AXBlade::BeginPlay()
{
	Super::BeginPlay();
	
}


