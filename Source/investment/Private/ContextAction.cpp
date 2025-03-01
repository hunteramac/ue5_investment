// Fill out your copyright notice in the Description page of Project Settings.


#include "ContextAction.h"
#include "AccessUtils.h"

UContextAction* UContextAction::AddAction(
	UObject* InWorldContextObject, 
	FText ActionDeclaration,
	UTextPortrayal* textPortrayal
)
{
	
	UContextAction* NewAction = NewObject< UContextAction>();

	if (textPortrayal) {
		NewAction->ActionDeclaration = FText::FromName(textPortrayal->GetFName());
	}
	else {
		NewAction->ActionDeclaration = ActionDeclaration;
	}

	
	NewAction->WorldContextObject = InWorldContextObject;
	return NewAction;
}

void UContextAction::Activate()
{
	ActionHandlerDelegate.BindDynamic(this, &UContextAction::OnHandleAction);
	GetPlayerInterface(WorldContextObject->GetWorld())->ShowContextAction(ActionDeclaration, ActionHandlerDelegate);
}

void UContextAction::OnHandleAction(int32 ignore)
{
	HandleAction.Broadcast();
}
