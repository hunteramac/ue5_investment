// Fill out your copyright notice in the Description page of Project Settings.

#include "Portray.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerInterface.h"
#include "AccessUtils.h"

UPortray::UPortray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("SceneGraph");
#endif

	// We want to use the action declaration text sent to the player, on the outpin.
	OutputPins[0].PinName = "Out";
	RefreshOutputs();
}

void UPortray::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!PropertyChangedEvent.Property)
	{
		return;
	}
	else
	{
		//// Use the table ID and key if provided instead.
		//if (!tableId.IsNone() && !tableKey.IsEmpty())
		//{
		//	//FTextKey tableKeyReal = FTextKey(tableKey);
		//	PortrayalNarration.FromStringTable(tableId, tableKey);
		//	return;
		//}

		RefreshOutputs();
		OnReconstructionRequested.ExecuteIfBound();
	}
}

void UPortray::RefreshOutputs()
{
	FName inputName = InputPins[0].PinName;

	OutputPins[0].PinName = "Out";
	//if (!PortrayalNarration.IsEmpty())
	//	OutputPins[0].PinName = FName(PortrayalNarration.ToString());
	//else
	//	OutputPins[0].PinName = "Text Portrayal";
}

void UPortray::ExecuteInput(const FName& PinName)
{
	// Not a great design method, for prototyping, we'll have text override the data table handling
	if (!PortrayalNarration.IsEmpty())
	{
		finPortrayal.BindDynamic(this, &UPortray::OnPortrayFinished);//BindUObject(this, &UPortray::OnPortrayFinished);
		GetPlayerInterface(GetWorld())->DoTextScreenPlayPortrayal(PortrayalNarration, finPortrayal);
		return;
	}

	if (!screenPlay)
	{
		TriggerFirstOutput(true);
		return;
	}

	// Proceed only if data table has screenplay format.
	if (screenPlay->GetRowStruct() != FScreenPlayEntry::StaticStruct())
	{
		TriggerFirstOutput(true);
	}
	
	// Figure out if what designer provided is valid. If it is, tell GM to portray it.
	// Where it is the blocks, NOT, the table, is passed down.

	finPortrayal.BindDynamic(this, &UPortray::OnPortrayFinished);

	TArray<FScreenPlayEntry*> rows;
	screenPlay->GetAllRows("portray", rows);

	//APlayerController* playerControl = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//UPlayerInterface* playerInterface = Cast<UPlayerInterface>(playerControl->GetComponentByClass(UPlayerInterface::StaticClass()));

	//playerInterface->DoTextScreenPlayPortrayal(rows, finPortrayal);
	//
	
	GetPlayerInterface(GetWorld())->DoTextScreenPlayPortrayal(rows, finPortrayal);

	// gameManager.portray(rows);
	// wait for game manager to tell us job done. Probably by passing it a delegate.
}

void UPortray::OnPortrayFinished()
{
	TriggerFirstOutput(true);
}

FString UPortray::GetNodeDescription() const
{
	if (!PortrayalNarration.IsEmpty())
	{
		if (PortrayalNarration.IsFromStringTable())
		{
			FName tableId;
			FTextKey textKey;
			FTextInspector::GetTableIdAndKey(PortrayalNarration, tableId, textKey);
			return textKey.ToString();//PortrayalNarration.ToString());
		}
		else
			return FString("");
	}

	if (!screenPlay)
		return FString("No screenplay");
	if (screenPlay->GetRowStruct() != FScreenPlayEntry::StaticStruct())
		return FString("Bad Screenplay format. Incorrect Datatable row entry.");

	return screenPlay->GetFName().ToString();
}