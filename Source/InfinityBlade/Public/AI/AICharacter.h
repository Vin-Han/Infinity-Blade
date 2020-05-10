// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"
#include "Animation/AnimMontage.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Weapon/Weapon.h"
#include "Components/ProgressBar.h"
#include "AICharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacter();
	/**/
	UPROPERTY(VisibleAnyWhere)
		UWidgetComponent* AIWidget;

	UPROPERTY()
		UProgressBar* HPBar;
	UPROPERTY(VisibleAnyWhere,Category = "HP")
		float TotalHP;
	UPROPERTY(VisibleAnyWhere, Category = "HP")
		float CurHP;
	UPROPERTY()
		UTextBlock* CurHpText;
	UPROPERTY()
		UTextBlock* TotalHpText;
	/**/
	bool bIsDead;
	/**/
	UPROPERTY(EditAnyWhere, Category = "AI")
		UBehaviorTree* BehaviorTree;
	/**/
	UPROPERTY(EditAnyWhere, Category = "Weapon")
		TSubclassOf<AWeapon> AIWeaponClass;

	UPROPERTY(EditAnyWhere, Category = "Montage")
		TArray<UAnimMontage*> AttackMontageClass;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* DamageMontage;
	UPROPERTY(EditAnyWhere, Category = "Montage")
		UAnimMontage* DeathMontage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;



};
