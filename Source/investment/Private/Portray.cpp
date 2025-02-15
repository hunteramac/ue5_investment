// Fill out your copyright notice in the Description page of Project Settings.


#include "Portray.h"

UPortray::UPortray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UPortray::ExecuteInput(const FName& PinName)
{
	if(!screenPlay)
		TriggerFirstOutput(true);

	//screenPlay->row

	//const UScriptStruct ExpectedRowType(FScreenPlayEntry);

	TriggerFirstOutput(true);
}

FString UPortray::GetNodeDescription() const
{
	if (!screenPlay)
		return FString("No screenplay");
	return screenPlay->GetFName().ToString();
}