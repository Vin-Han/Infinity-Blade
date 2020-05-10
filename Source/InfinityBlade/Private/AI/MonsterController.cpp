// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "../Public/AI/MonsterController.h"

AMonsterController::AMonsterController()
{
	BehaviorTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
	BlackBoardCom = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard"));
}

void AMonsterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	Monster = Cast<AAICharacter>(InPawn);

	AnimInstance = Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());

	if (Monster->BehaviorTree) {
		BlackBoardCom->InitializeBlackboard(*(Monster->BehaviorTree->BlackboardAsset));
		BehaviorTree->StartTree(*(Monster->BehaviorTree));
	}

	if (Monster->AIWeaponClass)
	{
		AIWeapon = GetWorld()->SpawnActor<AWeapon>(Monster->AIWeaponClass);
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget,EAttachmentRule::KeepRelative,EAttachmentRule::KeepRelative,true);
		AIWeapon->AttachToComponent(Monster->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
		AIWeapon->CapsuleCom->OnComponentBeginOverlap.AddDynamic(this,&AMonsterController::WeaponOverlapDamage);
	}
}

void AMonsterController::WeaponOverlapDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult)
{
	if (AnimInstance->bIsPlaying && !AnimInstance->bIsStop)
	{
		UGameplayStatics::ApplyDamage(OtherActor,2,this,Monster,nullptr);
	}
}
