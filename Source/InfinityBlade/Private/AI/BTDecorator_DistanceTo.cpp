// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BTDecorator_DistanceTo.h"

bool UBTDecorator_DistanceTo::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AMonsterController* Controller		= Cast<AMonsterController>(OwnerComp.GetAIOwner());

	UBlackboardComponent* Bboard		= Controller->BlackBoardCom;

	FVector TargetLocation = Bboard->GetValueAsVector(TEXT("TargetLocation"));

	float TempDistance = FVector::Distance(TargetLocation, Controller->GetPawn()->GetActorLocation());

	if (TempDistance >= Distance)
		return true;
	return false;
}
