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
	FText textToShow;
	// get text from data asset
	if (TextPortrayalAsset)
	{
		FName name = TextPortrayalAsset->GetFName();

		UE_LOG(LogTemp, Display, TEXT("%s"), *name.ToString());
		if (TextPortrayalAsset->TextPortrayal.portrayal.IsEmpty())
		{
			
			textToShow = FText::FromString(name.ToString());
		}
		else
		{
			textToShow = TextPortrayalAsset->TextPortrayal.portrayal;
			UE_LOG(LogTemp, Display, TEXT("%s"), *textToShow.ToString());
		}
	}
	else 
	{
		textToShow = FText::FromString(FString("Text asset not provided."));
	}

	callBack.BindDynamic(this, &UBpSceneSegment::PortrayalCompleted);
	GetPlayerInterface(worldContextObject->GetWorld())->DoTextScreenPlayPortrayal(textToShow, callBack);
}

void UBpSceneSegment::PortrayalCompleted()
{
	Continue.Broadcast();//Continue.ExecuteIfBound();
}
