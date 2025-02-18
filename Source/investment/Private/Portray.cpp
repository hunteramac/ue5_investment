// Fill out your copyright notice in the Description page of Project Settings.

#include "Portray.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerInterface.h"

UPortray::UPortray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("SceneGraph");
#endif
}

void UPortray::ExecuteInput(const FName& PinName)
{
	if(!screenPlay)
		TriggerFirstOutput(true);


	// Proceed only if data table has screenplay format.
	if (screenPlay->GetRowStruct() != FScreenPlayEntry::StaticStruct())
	{
		TriggerFirstOutput(true);
	}
	
	// Figure out if what designer provided is valid. If it is, tell GM to portray it.
	// Where it is the blocks, NOT, the table, is passed down.

	TArray<FScreenPlayEntry*> rows;
	screenPlay->GetAllRows("portray", rows);

	APlayerController* playerControl = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UPlayerInterface* playerInterface = Cast<UPlayerInterface>(playerControl->GetComponentByClass(UPlayerInterface::StaticClass()));
	
	finPortrayal.BindUObject(this, &UPortray::OnPortrayFinished);

	playerInterface->DoTextScreenPlayPortrayal(rows, finPortrayal);
	
	// gameManager.portray(rows);
	// wait for game manager to tell us job done. Probably by passing it a delegate.
}

void UPortray::OnPortrayFinished()
{
	TriggerFirstOutput(true);
}

FString UPortray::GetNodeDescription() const
{
	if (!screenPlay)
		return FString("No screenplay");
	if (screenPlay->GetRowStruct() != FScreenPlayEntry::StaticStruct())
		return FString("Bad Screenplay format. Incorrect Datatable row entry.");

	return screenPlay->GetFName().ToString();
}