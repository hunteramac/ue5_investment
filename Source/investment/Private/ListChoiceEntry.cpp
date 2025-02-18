// Fill out your copyright notice in the Description page of Project Settings.


#include "ListChoiceEntry.h"

void UListChoiceEntry::ListChoiceMade()
{
	if(ListData.callBack.IsBound())
		ListData.callBack.ExecuteIfBound(ListData.entryNumber);
}

void UListChoiceEntry::SetupListEntryData(FListEntry data)
{
	ListEntryText = data.entryText;
	ListEntryIndex = data.entryNumber;
}
