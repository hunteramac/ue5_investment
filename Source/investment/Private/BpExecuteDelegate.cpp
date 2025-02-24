// Fill out your copyright notice in the Description page of Project Settings.


#include "BpExecuteDelegate.h"

UBpExecuteDelegate* UBpExecuteDelegate::ExecuteDelegate(
	UObject* InWorldContextObject, 
	FDelegateContainer delegateContainer
)
{
	UBpExecuteDelegate* newDelegateExecutor = NewObject < UBpExecuteDelegate >();
	newDelegateExecutor->worldContextObject = InWorldContextObject;
	newDelegateExecutor->toExecute = delegateContainer;
	return newDelegateExecutor;
}

void UBpExecuteDelegate::Activate()
{
	toExecute.handler.ExecuteIfBound();
}
