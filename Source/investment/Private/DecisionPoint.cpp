// Fill out your copyright notice in the Description page of Project Settings.


#include "DecisionPoint.h"

FString UDecisionPoint::GetNodeDescription() const
{
	if (!DecisionPointActions)
		return FString("No decison point actions provided.");
	else if (DecisionPointActions->GetRowStruct() != FDecisionPointAction::StaticStruct())
		return FString("Bad decision point format. Incorrect Datatable row entry.");
	else
		return DecisionPointActions->GetFName().ToString();
}

void UDecisionPoint::ExecuteInput(const FName& PinName)
{
	// Setup a callback for UI to message back
	playerChoiceMade.BindUObject(this, &UDecisionPoint::OnPlayerChoiceMade);

	// Dispatch a message to the UI to invite the player to choose from the action declarations listed.

	// wait on the callback
	
}

void UDecisionPoint::OnPlayerChoiceMade(int32 ListChoiceIndex) {
	//verify index is not outside OutputPins
	if(ListChoiceIndex >= OutputPins.Num())
	{
		//Should throw an error here.
	}
	else
	{
		TriggerOutput(OutputPins[ListChoiceIndex].PinName, false);
	}
}