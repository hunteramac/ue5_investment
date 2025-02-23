// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearDecisionPoint.h"
#include "PlayerInterface.h"
#include "AccessUtils.h"

UClearDecisionPoint* UClearDecisionPoint::ClearActiveContextActions(UObject* InWorldContextObject)
{
	UClearDecisionPoint* clearContextActions = NewObject< UClearDecisionPoint>();
	clearContextActions->worldContextObject = InWorldContextObject;
	return clearContextActions;
}

void UClearDecisionPoint::Activate()
{
	GetPlayerInterface(worldContextObject->GetWorld())->ClearContextActions();
}
