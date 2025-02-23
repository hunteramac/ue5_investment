// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ClearDecisionPoint.generated.h"

/**
 * The designer uses this node to eliminate any active context actions being presented to the player.
 * The main purpose of this is when a point of critical inaction has been reached, and new state unfolds.
 */
UCLASS()
class INVESTMENT_API UClearDecisionPoint : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UClearDecisionPoint* ClearActiveContextActions(
		UObject* InWorldContextObject
	);

	virtual void Activate() override;

protected:
	TObjectPtr<UObject> worldContextObject;
};
