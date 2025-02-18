// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
//#include "InstancedStruct.h"
//
//#include "Templates/Tuple.h"
//
////#include "uLang/Common/Misc/Optional.h"
//
//#include "Containers/StaticArray.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyStructs.generated.h"

DECLARE_DELEGATE(FCallBack);

DECLARE_DYNAMIC_DELEGATE_OneParam(FListChoiceMade, int32, ListChoiceIndex);

USTRUCT(BlueprintType)
struct FDecisionPointAction : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText PlayerFacingActionDeclaration;
};

USTRUCT(BlueprintType)
struct FNarration : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText NarrationText;
};

USTRUCT(BlueprintType)
struct FDialogLine : public FTableRowBase
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
	TArray< FDialogLine > dialogLine;
};