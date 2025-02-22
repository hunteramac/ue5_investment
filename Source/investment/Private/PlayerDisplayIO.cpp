// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDisplayIO.h"

void UPlayerDisplayIO::NativeConstruct()
{
	Super::NativeConstruct();
}

float UPlayerDisplayIO::SetScreenPlayEntry_ThenDraw(FScreenPlayEntry& entry)
{
	ScreenPlayBlockToDraw = entry;
	//This function will take data we've saved, and render it out.
	DrawScreenPlayEntryFromData();

	return timeToShowScreenPlayEntry;
}

float UPlayerDisplayIO::PortrayRawTextAsNarration(FText PortrayalNarration)
{
	RawPortrayalNarration = PortrayalNarration;

	DrawScreenPlayEntryFromData();

	return timeToShowScreenPlayEntry;
}

void UPlayerDisplayIO::ShowListChoice(TArray<FDecisionPointAction*> dpActions, FListChoiceMade callBack)
{
	//Store to data
	ListEntries.Empty();
	for (int i = 0; i < dpActions.Num(); ++i)
	{
		FListEntry newEntry;
		newEntry.entryNumber = i;
		newEntry.callBack = callBack;
		newEntry.parent = this;

		//if(callBack.IsBound())
		//{
		//	callBack.Execute(1);
		//}

		newEntry.entryText = (*dpActions[i]).PlayerFacingActionDeclaration;

		ListEntries.Add(newEntry);
	}
		//ListEntries[i] = (*dpActions[i]).PlayerFacingActionDeclaration;
	//ListChoiceCallBack = callBack;

	DrawListChoice();
}

void UPlayerDisplayIO::ShowAtomicListChoice(FText ActionDeclaration, FListChoiceMade ActionHandler) {
	FListEntry NewEntry(0, ActionDeclaration, ActionHandler, this);

	ListEntries.Add(NewEntry);

	// The assumption is if list choice allready exists, it will just add the most recently added entry.
	DrawListChoice();
}

void UPlayerDisplayIO::CleanupListChoice()
{
	ListEntries.Empty();
	CleanupListChoiceUI();
}

//void UPlayerDisplayIO::PlayerMadeListChoice(int32 ListChoice)
//{
//	ListChoiceCallBack.ExecuteIfBound(ListChoice);
//}
