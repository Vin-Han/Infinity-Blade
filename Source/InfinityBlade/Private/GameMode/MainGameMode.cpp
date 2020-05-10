// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/GameMode/MainGameMode.h"
#include "../Public/Character/XPlayerState.h"
#include "../Public/Character/XPlayerController.h"
#include "GameFramework/Character.h"
#include "UObject/ConstructorHelpers.h"

AMainGameMode::AMainGameMode() {

	ConstructorHelpers::FClassFinder<ACharacter> CharecterFinder(TEXT("/Game/Character/Blueprint/BP_XCharacter"));
	DefaultPawnClass = CharecterFinder.Class;
	PlayerControllerClass = AXPlayerController::StaticClass();

	PlayerStateClass = AXPlayerState::StaticClass();
}

void AMainGameMode::BeginPlay()
{

}
