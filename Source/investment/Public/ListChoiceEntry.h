// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStructs.h"

#include "ListChoiceEntry.generated.h"

/**
 * 
 */
UCLASS()
class INVESTMENT_API UListChoiceEntry : public UUserWidget

{
	GENERATED_BODY()

protected:

	FListEntry ListData;

	FListChoiceMade callBack;

	UPROPERTY(BlueprintReadWrite)
	FText ListEntryText;
	UPROPERTY(BlueprintReadWrite)
	int32 ListEntryIndex;
	
	UFUNCTION(BlueprintCallable)
	void ListChoiceMade();

	UFUNCTION(BlueprintCallable)
	void SetupListEntryData(FListEntry data);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetupListEntryUI();
};
