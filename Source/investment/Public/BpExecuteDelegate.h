// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyStructs.h"
#include "BpExecuteDelegate.generated.h"

DECLARE_DYNAMIC_DELEGATE(FBpHandler);

/**
 * 
 */
UCLASS()
class INVESTMENT_API UBpExecuteDelegate : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UBpExecuteDelegate* ExecuteDelegate(
		UObject* InWorldContextObject, FDelegateContainer delegateContainer
	);

	FDelegateContainer toExecute;

	virtual void Activate() override;

protected:
	TObjectPtr<UObject> worldContextObject;
	
};
