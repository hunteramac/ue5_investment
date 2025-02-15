// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Actor.h"
#include "TimerManager.h"
//WorldContextObject->GetWorld()->GetTimerManager().SetTimer()
#include "PlayerInterface.h"

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
	//Basecase, if we have itterated through elements, cease recursion and execute callback.
	if (curInd > ScreenPlayEntries.Num())
	{
		callBack.ExecuteIfBound();
		return;
	}

	//playerDisplay->DisplayScreenPlayEntry(ScreenPlayEntries[0]);
	FTimerHandle UnusedHandle;
	FTimerDelegate TimerDel;

	playerDisplay->DisplayScreenPlayEntry(ScreenPlayEntries[curInd]);

	TimerDel.BindUFunction(this, FName("TextScreenPlayPortrayal"), ScreenPlayEntries, callBack, curInd + 1);

	//FCallBack UnusedHandle;
	GetOwner()->GetWorldTimerManager().SetTimer(
		UnusedHandle,
		TimerDel,
		10.0f,
		false
	);
}

void UPlayerInterface::DoTextScreenPlayPortrayal(TArray<FScreenPlayEntry*> ScreenPlayEntries, FCallBack callBack)
{
	// Start recursion
	TextScreenPlayPortrayal(ScreenPlayEntries, callBack, 0);
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

