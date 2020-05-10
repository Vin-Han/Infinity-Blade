// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Weapon/Weapon.h"

// Sets default values
AWeapon::AWeapon()
{

	WeaponMesh	= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	CapsuleCom = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleCom->SetupAttachment(WeaponMesh);
}

