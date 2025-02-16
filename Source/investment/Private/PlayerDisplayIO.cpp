// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDisplayIO.h"

void UPlayerDisplayIO::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayerDisplayIO::SetScreenPlayEntry_ThenDraw(FScreenPlayEntry& entry)
{
	ScreenPlayBlockToDraw = entry;
	//This function will take data we've saved, and render it out.
	DrawScreenPlayEntryFromData();
}
