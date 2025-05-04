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
		if (textPortrayal->TextPortrayal.actionDeclaration.IsEmpty())
			NewAction->ActionDeclaration = FText::FromName(textPortrayal->GetFName());
		else
			NewAction->ActionDeclaration = textPortrayal->TextPortrayal.actionDeclaration;
	}
	else {
		NewAction->ActionDeclaration = ActionDeclaration;
	}

	NewAction->WorldContextObject = InWorldContextObject;
	return NewAction;
}

UContextAction* UContextAction::AddContextAction(UObject* InWorldContextObject, FText ActionDeclaration, FText ContextTag)
{
	UContextAction* NewAction = NewObject< UContextAction>();

	// if a context tag was provided, store it in the optional to pass down to player interface
	if(!ContextTag.IsEmpty())
		NewAction->ContextTag = ContextTag;
	
	NewAction->ActionDeclaration = ActionDeclaration;

	NewAction->WorldContextObject = InWorldContextObject;
	return NewAction;
}

void UContextAction::Activate()
{
	ActionHandlerDelegate.BindDynamic(this, &UContextAction::OnHandleAction);
	GetPlayerInterface(WorldContextObject->GetWorld())->AddContextAction(ActionDeclaration, ActionHandlerDelegate, ContextTag);
}

void UContextAction::OnHandleAction(int32 ignore)
{
	HandleAction.Broadcast();
}
