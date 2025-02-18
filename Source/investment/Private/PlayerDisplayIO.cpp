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

void UPlayerDisplayIO::ShowListChoice(TArray<FDecisionPointAction*> dpActions, FListChoiceMade callBack)
{
	//Store to data
	ListEntries.Empty();
	for (int i = 0; i < dpActions.Num(); ++i)
	{
		FListEntry newEntry;
		newEntry.entryNumber = i;
		newEntry.callBack = callBack;

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

//void UPlayerDisplayIO::PlayerMadeListChoice(int32 ListChoice)
//{
//	ListChoiceCallBack.ExecuteIfBound(ListChoice);
//}
