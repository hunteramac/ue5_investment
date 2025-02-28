// Fill out your copyright notice in the Description page of Project Settings.


#include "BpSceneSegment.h"
#include "PlayerInterface.h"
#include "AccessUtils.h"

UBpSceneSegment* UBpSceneSegment::SceneSegment(UObject* InWorldContextObject, UTextPortrayal* textPortrayal)
{
	UBpSceneSegment* sceneSegment = NewObject< UBpSceneSegment>();
	sceneSegment->TextPortrayalAsset = textPortrayal;
	sceneSegment->worldContextObject = InWorldContextObject;

	return sceneSegment;
}

void UBpSceneSegment::Activate()
{
	// get text from data asset
	FName name = TextPortrayalAsset->GetFName();

	FText nameText = FText::FromString(name.ToString());

	callBack.BindDynamic(this, &UBpSceneSegment::PortrayalCompleted);
	GetPlayerInterface(worldContextObject->GetWorld())->DoTextScreenPlayPortrayal(nameText, callBack);
}

void UBpSceneSegment::PortrayalCompleted()
{
	Continue.Broadcast();//Continue.ExecuteIfBound();
}
