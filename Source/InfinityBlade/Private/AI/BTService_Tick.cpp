// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/BTService_Tick.h"

void UBTService_Tick::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {

	AMonsterController* Controller = Cast<AMonsterController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* Bboard = Controller->BlackBoardCom;
	AAICharacter* Monster = Cast<AAICharacter>(Controller->GetPawn());

	Bboard->SetValueAsObject(TEXT("SelfActor"), Monster);
	Bboard->SetValueAsVector(TEXT("SelfDirection"), Monster->GetMesh()->GetComponentRotation().Vector());
	Bboard->SetValueAsVector(TEXT("TargetLocation"), UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->GetActorLocation());

}