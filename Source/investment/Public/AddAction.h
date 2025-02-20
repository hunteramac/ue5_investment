// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "MyStructs.h"
#include "AddAction.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "AddAction"))
class INVESTMENT_API UAddAction final: public UFlowNode
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere)
	FText ActionDeclaration;

	void OnActionHandle();
	FCallBack ActionHandlerDelegate;

#if WITH_EDITOR
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent & PropertyChangedEvent) override;
#endif

protected:
	virtual void ExecuteInput(const FName& PinName) override;

private:
	void RefreshOutputs();
};
