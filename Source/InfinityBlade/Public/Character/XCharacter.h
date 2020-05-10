// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Skill/IceStone.h"
#include "Animation/AnimMontage.h"
#include "Skill/XBlade.h"
#include "../Weapon/Weapon.h"
#include "Pickup/ItemInfor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "XCharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AXCharacter();
	/**/
	UPROPERTY(VisibleAnyWhere,Category = "Component")
		UCameraComponent* CameraCom;
	UPROPERTY(EditAnyWhere, Category = "Weapon")
		TSubclassOf<AWeapon> XWeaponClass;
	UPROPERTY(EditAnyWhere, Category = "Skill")
		TSubclassOf<AXBlade> XBladeClass;
	UPROPERTY(EditAnyWhere, Category = "Skill")
		TSubclassOf<AIceStone> IceStoneClass;

	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* AtkMontage;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* IceStoneMontage;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* CureMontage;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* ThunderMontage;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* XBladeMontage;


	/**/
	UPROPERTY(EditAnyWhere, Category = "State")
		float TotalHP;
	UPROPERTY(EditAnyWhere, Category = "State")
		float TotalMP;
	UPROPERTY(EditAnyWhere, Category = "State")
		float NormalAtk;
	UPROPERTY(EditAnyWhere, Category = "State")
		bool bIsXBlade;

	/**/
	UPROPERTY()
		TArray<FPickupInfo> ItemList;
protected:
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
};
