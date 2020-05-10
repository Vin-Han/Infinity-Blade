// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameInstance.h"
#include "Engine/Engine.h"

void UCustomGameInstance::Init()
{
	UGameInstance::Init();
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);

	LoadWidget = CreateWidget<ULoadUserWidget>(this, LoadClass<ULoadUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_LoadUserWidget.BP_LoadUserWidget_c'")));
}

void UCustomGameInstance::PreLoadMap(const FString& Map)
{
	Attribute.bWaitForManualStop = true;
	Attribute.WidgetLoadingScreen = LoadWidget->TakeWidget();
	GetMoviePlayer()->SetupLoadingScreen(Attribute);

}

void UCustomGameInstance::PostLoadMap(UWorld* World)
{
}

bool UCustomGameInstance::GetLoadStatus()
{
	return GetMoviePlayer()->IsLoadingFinished();
}

void UCustomGameInstance::LoadNewPlayer(FString NickName, FString Score)
{
	ContextMap.Add(NickName, Score);
}

