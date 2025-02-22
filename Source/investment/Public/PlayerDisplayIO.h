// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStructs.h"

#include "PlayerDisplayIO.generated.h"

USTRUCT(BlueprintType)
struct FListEntry
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 entryNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText entryText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FListChoiceMade callBack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UPlayerDisplayIO* parent;
};

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

	UPROPERTY(BlueprintReadWrite)
	FText RawPortrayalNarration;

	/// <summary>
	/// Used to message the player interface, computed during UI blueprint events
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	float timeToShowScreenPlayEntry;

public:
	virtual void NativeConstruct() override;
	//virtual void DisplayDialogLine(FDialog);
	//virtual void DisplayNarration(FNarration);

	// Define this in blueprint.
	//UFUNCTION(BlueprintImplementableEvent)

	/// <summary>
	/// 
	/// </summary>
	/// <param name="entry"> returns the amount of time the UI determines the line should remain on screen for. </param>
	float SetScreenPlayEntry_ThenDraw(FScreenPlayEntry& entry);
	
	float PortrayRawTextAsNarration(FText PortrayalNarration);

	/// <summary>
	/// Implemented on Blueprint side to filter data to UI elements
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
	void DrawScreenPlayEntryFromData();

protected:

	UPROPERTY(BlueprintReadWrite)
	TArray<FListEntry> ListEntries;


	//UFUNCTION(BlueprintCallable)
	//void PlayerMadeListChoice(int32 ListChoice);

	//FListChoiceMade ListChoiceCallBack;

public:
	void ShowListChoice(TArray<FDecisionPointAction*> dpActions, FListChoiceMade callBack);

	void ShowAtomicListChoice(FText ActionDeclaration, FListChoiceMade ActionHandler);

	UFUNCTION(BlueprintImplementableEvent)
	void DrawListChoice();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CleanupListChoiceUI();

	void CleanupListChoice();

};
