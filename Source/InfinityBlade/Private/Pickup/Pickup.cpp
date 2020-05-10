// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "../Public/Pickup/Pickup.h"
#include "../Public/Character/XCharacter.h"

// Sets default values
APickup::APickup()
{
	CollisionCom = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	MeshCom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = CollisionCom;
	MeshCom->SetupAttachment(CollisionCom);

	CollisionCom->OnComponentBeginOverlap.AddDynamic(this,&APickup::PickupOverlapDamage);
}

void APickup::PickupOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult)
{
	AXCharacter* Player = Cast<AXCharacter>(OtherActor);
	Player->ItemList.Add(ItemInfor);
	Destroy();
}

