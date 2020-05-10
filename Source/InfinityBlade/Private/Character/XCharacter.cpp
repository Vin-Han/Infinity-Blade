// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Character/XCharacter.h"
#include "Engine/Engine.h"
#include "../Public/Character/XPlayerController.h"

// Sets default values
AXCharacter::AXCharacter()
{
	//PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = 1  ;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	CameraCom = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraCom->SetupAttachment(RootComponent);
	CameraCom->bUsePawnControlRotation = false;
	bIsXBlade = false;
	TotalHP = 300;
	TotalMP = 300;
}

// Called when the game starts or when spawned
void AXCharacter::BeginPlay()
{
	Super::BeginPlay();
}

float AXCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	AXPlayerController* ControlCom = Cast<AXPlayerController> (this->GetController());
	ControlCom->UpDateProgressBar(Damage,0);
	return Damage;
}

