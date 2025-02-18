// Fill out your copyright notice in the Description page of Project Settings.


#include "DecisionPoint.h"
#include "AccessUtils.h"

UDecisionPoint::UDecisionPoint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("SceneGraph");
#endif
	RefreshOutputs();
}

FString UDecisionPoint::GetNodeDescription() const
{
	if (!DecisionPoint)
		return FString("No decision point actions provided.");
	else if (DecisionPoint->GetRowStruct() != FDecisionPointAction::StaticStruct())
		return FString("Bad decision point format. Incorrect Datatable row entry.");
	else
		return DecisionPoint->GetFName().ToString();
}

void UDecisionPoint::OnPlayerChoiceMade(int32 ListChoiceIndex) {
	//verify index is not outside OutputPins
	if (ListChoiceIndex >= OutputPins.Num())
	{
		//Should throw an error here.
	}
	else
	{
		TriggerOutput(OutputPins[ListChoiceIndex].PinName, false);
	}
}

#if WITH_EDITOR
void UDecisionPoint::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
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

void UDecisionPoint::FixNode(UEdGraphNode* NewGraph)
{
	RefreshOutputs();
}

#endif

void UDecisionPoint::ExecuteInput(const FName& PinName)
{
	if (DecisionPoint && DecisionPoint->GetRowStruct() == FDecisionPointAction::StaticStruct())
	{
		TArray<FDecisionPointAction*> rows;
		DecisionPoint->GetAllRows("DecisionPoint", rows);
		// Setup a callback for UI to message back
		playerChoiceMade.BindUObject(this, &UDecisionPoint::OnPlayerChoiceMade);

		// Dispatch a message to the UI to invite the player to choose from the action declarations listed.
		GetPlayerInterface(GetWorld())->ShowDecisionPointChoice(rows, playerChoiceMade);
		// wait on the callback
	}
}

void UDecisionPoint::RefreshOutputs()
{
	if (DecisionPoint && DecisionPoint->GetRowStruct() == FDecisionPointAction::StaticStruct())
	{
		//get rows
		TArray<FDecisionPointAction*> rows;
		DecisionPoint->GetAllRows("DecisionPoint", rows);

		SetNumberedOutputPins(0, rows.Num()-1);
		for (int i = 0; i<rows.Num(); ++i)
		{
			OutputPins[i].PinName = FName(*rows[i]->PlayerFacingActionDeclaration.ToString());
		}
	}
	else 
	{
		OutputPins.Empty();
	}
}