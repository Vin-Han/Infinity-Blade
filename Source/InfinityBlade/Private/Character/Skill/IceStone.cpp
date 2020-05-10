// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Character/Skill/IceStone.h"

// Sets default values
AIceStone::AIceStone()
{
	IceParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	RootComponent = IceParticle;
	CollisionCom = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CollisionCom->SetupAttachment(IceParticle);

	CollisionCom->OnComponentBeginOverlap.AddDynamic(this, &AIceStone::OnOverlap);

	ProjectileCom = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileCom->InitialSpeed = 600.f;
	ProjectileCom->ProjectileGravityScale = 0;
	MPCost = 20;
	InitialLifeSpan = 2.f;
}

// Called when the game starts or when spawned
void AIceStone::BeginPlay()
{
	Super::BeginPlay();

}

void AIceStone::Shoot(FVector Direction)
{
	ProjectileCom->Velocity = Direction * ProjectileCom->InitialSpeed;
}

void AIceStone::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitRusult)
{
	UGameplayStatics::ApplyPointDamage(OtherActor,40, HitRusult.ImpactPoint, HitRusult,nullptr,this,nullptr);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ExplodeParicle, OtherActor->GetActorLocation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplodeSound, OtherActor->GetActorLocation());
	IceParticle->SetVisibility(false);
}
