// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyStructs.h"
#include "BpTextPortray.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBpAssignable);

/**
 * The designer puts this node into a blueprint graph and feeds it a text portrayal block. 
 * The implementation links into the UI systems to display/ portray the narration to the player.
 * At some point as per portrayal handling, the asyncronous node's output pin fires to continue execution after portrayal completes.
 */
UCLASS()
class INVESTMENT_API UBpTextPortray : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UBpTextPortray* TextNarrationPortrayal(
		UObject* InWorldContextObject, FText portrayalText
	);

	virtual void Activate() override;

	FText NarrationText;

	UPROPERTY(BlueprintAssignable)
	FBpAssignable Continue;

	FCallBack callBack;

protected:

	TObjectPtr<UObject> worldContextObject;

	UFUNCTION()
	void PortrayalCompleted();
};
