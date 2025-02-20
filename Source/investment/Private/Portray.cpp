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
}

void UPortray::ExecuteInput(const FName& PinName)
{
	// Not a great design method, for prototyping, we'll have text override the data table handling
	if (!PortrayalNarration.IsEmpty())
	{
		finPortrayal.BindUObject(this, &UPortray::OnPortrayFinished);
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

	finPortrayal.BindUObject(this, &UPortray::OnPortrayFinished);

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
		return FString(PortrayalNarration.ToString());
	}

	if (!screenPlay)
		return FString("No screenplay");
	if (screenPlay->GetRowStruct() != FScreenPlayEntry::StaticStruct())
		return FString("Bad Screenplay format. Incorrect Datatable row entry.");

	return screenPlay->GetFName().ToString();
}