// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/UI/MessageUserWidget.h"
#include"Engine/Engine.h"

bool UMessageUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));
	MessageBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Message")));

	CloseBtn->OnClicked.AddDynamic(this,&UMessageUserWidget::CloseBtnClickOnEvent);

	return true;
}

void UMessageUserWidget::CloseBtnClickOnEvent(){
	SetVisibility(ESlateVisibility::Hidden);
}

void UMessageUserWidget::ShowMessageOnScreen(FString Message){
	SetVisibility(ESlateVisibility::Visible);
	if (MessageBlock)
		MessageBlock->SetText(FText::FromString(Message));
}
