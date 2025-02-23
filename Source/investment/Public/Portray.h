// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "MyStructs.h"
#include "Portray.generated.h"

/**
 * 
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "Portray"))
class INVESTMENT_API UPortray final : public UFlowNode
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "ScreenPlay")
	UDataTable* screenPlay;

	//UPROPERTY(EditAnywhere, Category = "Table")
	//FName tableId;

	//UPROPERTY(EditAnywhere, Category = "Table")
	//FString tableKey;

	UPROPERTY(EditAnywhere, Category = "Table")
	FText PortrayalNarration;

protected:
	virtual void ExecuteInput(const FName& PinName) override;

	UFUNCTION()
	void OnPortrayFinished();

	FCallBack finPortrayal;

#if WITH_EDITOR
public:
	/// <summary>
	/// Show in the Flow graph if the input screenplay data table is provided, if it has valid row entries.
	/// If it does, show the screenplay data table name above the node to clearly show to content designer what the portray node is doing.
	/// </summary>
	/// <returns></returns>
	virtual FString GetNodeDescription() const override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	void RefreshOutputs();
};
