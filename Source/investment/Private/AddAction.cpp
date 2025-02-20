// Fill out your copyright notice in the Description page of Project Settings.

#include "AddAction.h"
#include "AccessUtils.h"

UAddAction::UAddAction(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("SceneGraph");
#endif

	// First is to continue main execution, the second is for the handler
	SetNumberedOutputPins(0, 1);

	// We want to use the action declaration text sent to the player, on the outpin.
	RefreshOutputs();
}

void UAddAction::OnActionHandle()
{
	TriggerOutput(OutputPins[1].PinName, true);
}

void UAddAction::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (!PropertyChangedEvent.Property)
	{
		return;
	}
	else
	{
		RefreshOutputs();
		OnReconstructionRequested.ExecuteIfBound();
	}
}

void UAddAction::ExecuteInput(const FName& PinName)
{
	// Setup the action handler 
	ActionHandlerDelegate.BindUObject(this, &UAddAction::OnActionHandle);
	//and send a request to the interface to display it to the player
	//GetPlayerInterface(GetWorld())->

	// Then continue main execution.
	TriggerFirstOutput(true);
}

void UAddAction::RefreshOutputs()
{
	OutputPins[1].PinName = FName(ActionDeclaration.ToString());
}