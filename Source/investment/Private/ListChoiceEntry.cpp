// Fill out your copyright notice in the Description page of Project Settings.

#include "ListChoiceEntry.h"
#include "AccessUtils.h"


void UListChoiceEntry::ListChoiceMade()
{
	// It'd probably be better (SOLID) if this was a chain of delegates
	// Where callBack would go to the UI, go to the interface, and to the flowNode
	if(callBack.IsBound())
		callBack.Execute(ListEntryIndex);

	//Ensure UI cleans up the list.
	parent->CleanupListChoice();
}

void UListChoiceEntry::SetupListEntryData(FListEntry data)
{
	// For some reason, taking the callback out of the struct was necessary to ensure 'isBound'
	// When list choice is made
	parent = data.parent;
	callBack = data.callBack;
	ListEntryText = data.entryText;
	ListEntryIndex = data.entryNumber;
}
