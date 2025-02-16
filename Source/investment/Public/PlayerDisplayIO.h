// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStructs.h"

#include "PlayerDisplayIO.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class INVESTMENT_API UPlayerDisplayIO : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite)
	FScreenPlayEntry ScreenPlayBlockToDraw;

public:
	virtual void NativeConstruct() override;
	//virtual void DisplayDialogLine(FDialog);
	//virtual void DisplayNarration(FNarration);

	// Define this in blueprint.
	//UFUNCTION(BlueprintImplementableEvent)
	void SetScreenPlayEntry_ThenDraw(FScreenPlayEntry& entry);

	/// <summary>
	/// Implemented on Blueprint side to filter data to UI elements
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
	void DrawScreenPlayEntryFromData();
};
