// Fill out your copyright notice in the Description page of Project Settings.


#include "BpTextPortray.h"
#include "PlayerInterface.h"
#include "AccessUtils.h"

UBpTextPortray* UBpTextPortray::TextNarrationPortrayal(UObject* InWorldContextObject, FText portrayalText)
{
	
	UBpTextPortray* textPortray = NewObject< UBpTextPortray>();
	textPortray->NarrationText = portrayalText;
	textPortray->worldContextObject = InWorldContextObject;

	return textPortray;
}

void UBpTextPortray::Activate()
{
	callBack.BindDynamic(this, &UBpTextPortray::PortrayalCompleted);
	GetPlayerInterface(worldContextObject->GetWorld())->DoTextScreenPlayPortrayal(NarrationText, callBack);
}

void UBpTextPortray::PortrayalCompleted()
{
	Continue.Broadcast();//Continue.ExecuteIfBound();
}
