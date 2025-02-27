// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerInterface.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
//WorldContextObject->GetWorld()->GetTimerManager().SetTimer()


// Sets default values for this component's properties
UPlayerInterface::UPlayerInterface()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

/*
Implements recursively iterating over the screen play entry, calling the UI to display, then displaying next after an interval
Once all entries have been displayed, executes the callBack delegate (a flow node is waiting on).
*/
void UPlayerInterface::TextScreenPlayPortrayal(TArray<FScreenPlayEntry*> ScreenPlayEntries, FCallBack callBack, int32 curInd) 
{
	//if we don't do this. the compiler optimizes out the curInd
	int32 thisCurInd = curInd;
	
	//Base case, if we have iterated through elements, cease recursion and execute callback.
	if (thisCurInd >= ScreenPlayEntries.Num())
	{
		OnPortrayalFinished(callBack);
		return;
	}
	else { //I think  there's an async thread bug here, if we don't have this else condition, things break

		//playerDisplay->DisplayScreenPlayEntry(ScreenPlayEntries[0]);
		//FTimerHandle UnusedHandle;
		//FTimerDelegate TimerDel;

		// get the value pointed to by DE refencing it
		float timeToDisplayEntry = playerDisplay->SetScreenPlayEntry_ThenDraw(*ScreenPlayEntries[thisCurInd]);

		TimerDel.BindUObject(this, &UPlayerInterface::TextScreenPlayPortrayal, ScreenPlayEntries, callBack, thisCurInd + 1);
		//TimerDel.BindUFunction(this, FName("TextScreenPlayPortrayal"), ScreenPlayEntries, callBack, curInd + 1);

		//FCallBack UnusedHandle;
		GetOwner()->GetWorldTimerManager().SetTimer(
			PortrayalTimerHandle,
			TimerDel,
			timeToDisplayEntry,
			false
		);
	}
}

void UPlayerInterface::DoTextScreenPlayPortrayal(TArray<FScreenPlayEntry*> ScreenPlayEntries, FCallBack callBack)
{
	// Start recursion
	TextScreenPlayPortrayal(ScreenPlayEntries, callBack, 0);
}

void UPlayerInterface::OnPortrayalFinished(FCallBack callBack) {
	callBack.ExecuteIfBound();
}


void UPlayerInterface::DoTextScreenPlayPortrayal(FText PortrayalNarration, FCallBack delegate)
{
	float timeToDisplayEntry = playerDisplay->PortrayRawTextAsNarration(PortrayalNarration);

	TimerDel.BindUObject(this, &UPlayerInterface::OnPortrayalFinished, delegate);

	GetOwner()->GetWorldTimerManager().SetTimer(
		PortrayalTimerHandle,
		TimerDel,
		timeToDisplayEntry,
		false
	);
}

void UPlayerInterface::ShowDecisionPointChoice(TArray<FDecisionPointAction*> dpActions, FListChoiceMade callBack)
{
	playerDisplay->ShowListChoice(dpActions, callBack);
}

void UPlayerInterface::ShowContextAction(FText ActionDeclaration, FListChoiceMade ActionHandler)
{
	playerDisplay->ShowAtomicListChoice(ActionDeclaration, ActionHandler);
		/*FPossibleContextAction(
			ActionDeclaration, 
			ActionHandler)*/
}

void UPlayerInterface::ClearContextActions()
{
	playerDisplay->CleanupListChoice();
}


// Called when the game starts
void UPlayerInterface::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerInterface::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerInterface::SkipPortrayalTimer()
{
	// if timer running
	if (GetWorld()->GetTimerManager().IsTimerActive(PortrayalTimerHandle)) 
	{
		GetWorld()->GetTimerManager().PauseTimer(
			PortrayalTimerHandle
		);

		TimerDel.ExecuteIfBound();
	}

}

