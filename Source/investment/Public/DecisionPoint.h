// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "MyStructs.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DecisionPoint.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "Decision Point"))
class INVESTMENT_API UDecisionPoint final : public UFlowNode
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "DecisionPoint")
	UDataTable* DecisionPoint;

	UPROPERTY(EditAnywhere, Category = "Utility")
	bool ForceUpdateNodeLinks;

#if WITH_EDITOR
public:
	/// <summary>
	/// Show in the Flow graph if the input decision point data table is provided, if it has valid row entries.
	/// If it does, show the decision point data table name above the node give an indicator to content designer of where action choices are coming from without
	/// needing to click onto the node and see it's details.
	/// </summary>
	/// <returns></returns>
	virtual FString GetNodeDescription() const override;

	//virtual bool CanUserAddOutput() const override { return true; }

	/// <summary>
	/// Parse input data table and update out pins.
	/// </summary>
	/// <param name="PropertyChangedEvent"></param>
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void FixNode(UEdGraphNode* NewGraph) override;

#endif

protected:
	virtual void ExecuteInput(const FName& PinName) override;
	FListChoiceMade playerChoiceMade;
	void OnPlayerChoiceMade(int32 ListChoiceIndex);

private:
	void RefreshOutputs();
};
