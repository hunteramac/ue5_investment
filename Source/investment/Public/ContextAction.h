// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyStructs.h"
#include "TextPortrayal.h"
#include "ContextAction.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBpAssignable);

/**
 * 
 */
UCLASS()
class INVESTMENT_API UContextAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UContextAction* AddAction(
		UObject* InWorldContextObject, 
		FText ActionDeclaration,
		UTextPortrayal* textPortrayal
	);

	virtual void Activate() override;

	FText ActionDeclaration;

	UFUNCTION()
	void OnHandleAction(int32 ignore);
	
	// Nodes exec pin
	UPROPERTY(BlueprintAssignable)
	FBpAssignable HandleAction;

	FListChoiceMade ActionHandlerDelegate;
protected:
	TObjectPtr<UObject> WorldContextObject;
};
