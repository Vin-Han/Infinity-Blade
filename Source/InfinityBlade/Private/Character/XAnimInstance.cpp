// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Character/XAnimInstance.h"
#include "../Public/Character/XPlayerController.h"
#include "Engine/Engine.h"

void UXAnimInstance::ReSetNormalAtk(){
	if(PlayerState)
		PlayerState->SetAtkDmg(NormalAtk);
}

void UXAnimInstance::UpdateAtk(float AtkChange)
{
	if (PlayerState)
		PlayerState->SetAtkDmg(PlayerState->GetAtkDmg() + AtkChange);
}

void UXAnimInstance::UpdateSpeed(){
	if (TryGetPawnOwner()!= nullptr)
		Speed = TryGetPawnOwner()->GetVelocity().Size();
}

void UXAnimInstance::AnimNotify_PlayerStart(UAnimNotify* Notify){
	bIsPlaying = true;
}

void UXAnimInstance::AnimNotify_EndStart(UAnimNotify* Notify){
	bIsPlaying = false;
}

void UXAnimInstance::AnimNotify_AtkStart(UAnimNotify* Notify)
{
	bIsAtking = true;
}

void UXAnimInstance::AnimNotify_AtkEnd(UAnimNotify* Notify)
{
	bIsAtking = false;
}

void UXAnimInstance::AnimNotify_2AttackInput(UAnimNotify* Notify){
	bIsAble2 = true;
	UpdateAtk();
}

void UXAnimInstance::AnimNotify_3AttackInput(UAnimNotify* Notify){
	bIsAble3 = true;
	UpdateAtk();
}

void UXAnimInstance::AnimNotify_4AttackInput(UAnimNotify* Notify){
	bIsAble4 = true;
	UpdateAtk();
}

void UXAnimInstance::AnimNotify_5AttackInput(UAnimNotify* Notify){
	bIsAble5 = true;
	UpdateAtk();
}

void UXAnimInstance::AnimNotify_ResetATKStatus(UAnimNotify* Notify){
	bIsAble2 = false;
	bIsAble3 = false;
	bIsAble4 = false;
	bIsAble5 = false;
	ReSetNormalAtk();
}

void UXAnimInstance::AnimNotify_SpawnIceStone(UAnimNotify* Notify)
{
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	AIceStone* IceStone =  GetWorld()->SpawnActor<AIceStone>(	XCharacter->IceStoneClass, 
																XCharacter->GetMesh()->GetSocketLocation(TEXT("IceStone_Socket")),
																XCharacter->GetActorRotation());
	IceStone->Shoot(XCharacter->GetActorRotation().Vector());
	AXPlayerController* XPlayerController = Cast<AXPlayerController>(XCharacter->GetController());
	XPlayerController->UpDateProgressBar(0, IceStone->MPCost);
}

void UXAnimInstance::AnimNotify_Cure(UAnimNotify* Notify)
{
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	AXPlayerController* XPlayerController = Cast<AXPlayerController>(XCharacter->GetController());
	XPlayerController->UpDateProgressBar(-20, 30);
}

void UXAnimInstance::AnimNotify_Thunder(UAnimNotify* Notify)
{
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	AXPlayerController* XPlayerController = Cast<AXPlayerController>(XCharacter->GetController());
	XPlayerController->UpDateProgressBar(0, 50);
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(XCharacter);
	UGameplayStatics::ApplyRadialDamageWithFalloff(GetWorld(), 80,20, XCharacter->GetActorLocation(), 100, 500, 1, nullptr, IgnoreActors, XCharacter,XPlayerController, ECollisionChannel::ECC_Visibility);
}

void UXAnimInstance::AnimNotify_XBlade(UAnimNotify* Notify)
{
	AXCharacter* XCharacter = Cast<AXCharacter>(TryGetPawnOwner());
	AXBlade* Blade = GetWorld()->SpawnActor<AXBlade>(XCharacter->XBladeClass);

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);
	Blade->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("XBlade_Socket"));
	NormalAtk = 100;

	AXPlayerController* XPlayerController = Cast<AXPlayerController>(XCharacter->GetController());
	XPlayerController->XWeapon->WeaponMesh->SetVisibility(false);
	XCharacter->bIsXBlade = true;
}
