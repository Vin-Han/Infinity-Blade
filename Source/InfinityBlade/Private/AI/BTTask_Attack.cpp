// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BTTask_Attack.h"

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	AMonsterController*	Controller		= Cast<AMonsterController>(OwnerComp.GetAIOwner());
	AAICharacter* Monster			= Cast<AAICharacter>(Controller->GetPawn());
	UAIAnimInstance* AIAnimInstance	= Cast<UAIAnimInstance>(Monster->GetMesh()->GetAnimInstance());

	if (!AIAnimInstance->bIsPlaying){
		Controller->SetFocus(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
		uint8 RandomAnim = FMath::FloorToInt(FMath::RandRange(0, Monster->AttackMontageClass.Num() - 1));
		AIAnimInstance->Montage_Play(Monster->AttackMontageClass[RandomAnim], 1.f);
	}

	return EBTNodeResult::Succeeded;
}