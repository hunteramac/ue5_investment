// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStructs.h"

#include "PlayerDisplayIO.generated.h"

/**
 * 
 */
UCLASS()
class INVESTMENT_API UPlayerDisplayIO : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void DisplayDialogLine(FDialog);
	virtual void DisplayNarration(FNarration);
	virtual void DisplayScreenPlayEntry(const FScreenPlayEntry*);
};
