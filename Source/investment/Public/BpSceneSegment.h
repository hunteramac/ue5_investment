// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyStructs.h"
#include "TextPortrayal.h"
#include "BpSceneSegment.generated.h"

/**
 * 
 */
UCLASS()
class INVESTMENT_API UBpSceneSegment : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public: 
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UBpSceneSegment* SceneSegment(
		UObject* InWorldContextObject, 
		UTextPortrayal* textPortrayal

	);

	virtual void Activate() override;

	UTextPortrayal* TextPortrayalAsset;

	UPROPERTY(BlueprintAssignable)
	FBpAssignable Continue;

	FCallBack callBack;

protected:
	TObjectPtr<UObject> worldContextObject;
	
	UFUNCTION()
	void PortrayalCompleted();
};
