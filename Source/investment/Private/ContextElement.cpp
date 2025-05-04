// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextElement.h"
#include "AccessUtils.h"

UContextElement* UContextElement::AddContextElement(
	UObject* InWorldContextObject,
	FText ContextElement,
	bool MakeDefaultSelection
)
{
	UContextElement* NewElement = NewObject<UContextElement>();
	NewElement->WorldContextObject = InWorldContextObject;
	NewElement->ContextElementName = ContextElement;
	NewElement->MakeDefault = MakeDefaultSelection;
	return NewElement;
}

void UContextElement::Activate()
{
	// Talk the UI, setup a context element to group actions under with the same tag

	// If designer set context as default, UI makes it selected at start.
	GetPlayerInterface(WorldContextObject->GetWorld())->AddContextElement(ContextElementName, MakeDefault);
}