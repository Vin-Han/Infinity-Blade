// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "MonsterController.h"
#include "AI/AIAnimInstance.h"
#include "BTDecorator_DistanceTo.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UBTDecorator_DistanceTo : public UBTDecorator
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnyWhere, Category = "Prop")
        float Distance;

public:
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
