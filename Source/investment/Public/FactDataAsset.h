// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FactDataAsset.generated.h"

USTRUCT()
struct FFactInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Event;

	UPROPERTY(EditAnywhere)
	bool Occurred;
};

/**
 * 
 */
UCLASS(BlueprintType)
class INVESTMENT_API UFactDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FFactInfo Facts;
};
