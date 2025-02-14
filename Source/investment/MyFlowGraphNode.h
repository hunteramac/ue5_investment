// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Graph/Nodes/FlowGraphNode.h"
#include "MyFlowGraphNode.generated.h"

DECLARE_DYNAMIC_DELEGATE(FPassHandler);
USTRUCT(BlueprintType)
struct FDelegateContainer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPassHandler handler;
};

/**
 * 
 */
UCLASS()
class INVESTMENT_API UMyFlowGraphNode : public UFlowGraphNode
{
	GENERATED_BODY()
//protected:
//	virtual void ExecuteInput(const FName& PinName) override;
//	virtual void Cleanup() override;
};
