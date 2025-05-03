// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextElement.h"

UContextElement* UContextElement::AddContextElement(UObject* InWorldContextObject, FText ElementName)
{
	UContextElement* NewElement = NewObject<UContextElement>();
	return NewElement;
}

void UContextElement::Activate()
{
	// Setup access to the exec pin which defines actions
}