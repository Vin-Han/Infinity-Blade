// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/LoadUserWidget.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
protected:
	TMap<FString, FString> ContextMap;


public:
	void LoadNewPlayer(FString NickName, FString Score);

	virtual void Init() override;

	FLoadingScreenAttributes Attribute;

	UPROPERTY()
		ULoadUserWidget* LoadWidget;

	UFUNCTION()
		void PreLoadMap(const FString& Map);

	UFUNCTION()
		void PostLoadMap(UWorld* World);

	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();

};
