// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "MyStructs.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DecisionPoint.generated.h"

DECLARE_DELEGATE_OneParam(FListChoiceMade, int32 /*ListChoiceIndex*/);

/**
 * 
 */
UCLASS()
class INVESTMENT_API UDecisionPoint : public UFlowNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "DecisionPoint")
	UDataTable* DecisionPointActions;

#if WITH_EDITOR
public:
	/// <summary>
	/// Show in the Flow graph if the input screenplay data table is provided, if it has valid row entries.
	/// If it does, show the decision point data table name above the node give an indicator to content designer of where action choices are coming from without
	/// needing to click onto the node and see it's details.
	/// </summary>
	/// <returns></returns>
	virtual FString GetNodeDescription() const override;
#endif

protected:
	virtual void ExecuteInput(const FName& PinName) override;
	FListChoiceMade playerChoiceMade;
	void OnPlayerChoiceMade(int32 ListChoiceIndex);
};
