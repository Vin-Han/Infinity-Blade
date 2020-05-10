// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/UI/ItemUserWidget.h"
#include "Character/XPlayerController.h"

bool UItemUserWidget::Initialize()
{
	if(!Super::Initialize())
		return false;
	Button_Use->OnClicked.AddDynamic(this,&UItemUserWidget::UseBtnClickOnEvent);
	return true;
}

void UItemUserWidget::UseBtnClickOnEvent()
{
	if (Player) {
		AXPlayerController* Controller = (Cast<AXPlayerController>(Player->GetController()));
		Controller->UpDateProgressBar(-HPEffect, -MPEffect);
		for (int i = 0; i < Player->ItemList.Num(); i++)
		{
			if (Player->ItemList[i].ID == this->pID)
			{
				Player->ItemList.RemoveAt(i);
				break;
			}
		}

		Controller->BagWidget->ScrollBox_List->RemoveChild(this);
	}
}
