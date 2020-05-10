// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/UI/LoadUserWidget.h"

bool ULoadUserWidget::Initialize()
{
	if(!Super::Initialize())
		return false;

	TextContinue = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Continue")));
	TextLoading = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Loading")));
	Loading = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("LoadingCir")));

	return true;
}
