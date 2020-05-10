// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/AI/AIAnimInstance.h"
#include "../Public/AI/MonsterController.h"

void UAIAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr)
		CurSpeed = TryGetPawnOwner()->GetVelocity().Size();
}

void UAIAnimInstance::AnimNotify_PlayStart(UAnimNotify* Notify)
{
	bIsPlaying = true;
}

void UAIAnimInstance::AnimNotify_PlayEnd(UAnimNotify* Notify)
{
	bIsPlaying = false;
}

void UAIAnimInstance::AnimNotify_StopStart(UAnimNotify* Notify)
{
	bIsStop = true;
}

void UAIAnimInstance::AnimNotify_StopEnd(UAnimNotify* Notify)
{
	bIsStop = false;
}

void UAIAnimInstance::AnimNotify_Death(UAnimNotify* Notify)
{
	AMonsterController* ControlCom = Cast<AMonsterController>(TryGetPawnOwner()->GetController());
	ControlCom->AIWeapon->Destroy();
	TryGetPawnOwner()->Destroy();
}
