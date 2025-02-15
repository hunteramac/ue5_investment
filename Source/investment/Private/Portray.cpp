// Fill out your copyright notice in the Description page of Project Settings.


#include "Portray.h"

UPortray::UPortray(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UPortray::ExecuteInput(const FName& PinName)
{
	TriggerFirstOutput(true);
}