// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TextPortrayal.generated.h"

USTRUCT()
struct FTextPortrayalInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText portrayal;
};

/**
 * 
 */
UCLASS()
class INVESTMENT_API UTextPortrayal : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FTextPortrayalInfo TextPortrayal;
	
};
