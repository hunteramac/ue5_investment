// Fill out your copyright notice in the Description page of Project Settings.


#include "ListChoiceEntry.h"

void UListChoiceEntry::ListChoiceMade()
{
	if(callBack.IsBound())
		callBack.Execute(ListData.entryNumber);
}

void UListChoiceEntry::SetupListEntryData(FListEntry data)
{
	// For some reason, taking the callback out of the struct was necessary to ensure 'isBound'
	// When list choice is made
	callBack = data.callBack;
	ListEntryText = data.entryText;
	ListEntryIndex = data.entryNumber;
}
