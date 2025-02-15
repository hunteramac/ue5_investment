// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nodes/FlowNode.h"
#include "Portray.generated.h"

USTRUCT(BlueprintType)
struct FNarration : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText NarrationText;
};

USTRUCT(BlueprintType)
struct FDialog : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText VoiceTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Comment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText SpeakingTo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DialogLine;
};

USTRUCT(BlueprintType)
struct FScreenPlayEntry : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray< FNarration >  narration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray< FDialog > dialogLine;
};

/**
 * 
 */
UCLASS(NotBlueprintable, meta = (DisplayName = "Portray"))
class INVESTMENT_API UPortray : public UFlowNode
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "ScreenPlay")
	UDataTable* screenPlay;

protected:
	virtual void ExecuteInput(const FName& PinName) override;

#if WITH_EDITOR
public:
	virtual FString GetNodeDescription() const override;
#endif
};
