// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyStructs.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ContextElement.generated.h"

/**
 * 
 */
UCLASS()
class INVESTMENT_API UContextElement : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UContextElement* AddContextElement(
		UObject* InWorldContextObject,
		FText ElementName
	);

	virtual void Activate() override;

	// Nodes exec pin
	UPROPERTY(BlueprintAssignable)
	FBpAssignable ContextActions;

	FText ContextElementName;
};
