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

void UPlayerInterface::RecursiveTextScreenPlayPortrayal() {	
	//playerDisplay->DisplayScreenPlayEntry(ScreenPlayEntries[0]);
}

void UPlayerInterface::DoTextScreenPlayPortrayal(TArray<FScreenPlayEntry*> ScreenPlayEntries, FCallBack callBack)
{
	FTimerHandle UnusedHandle;
	//FCallBack UnusedHandle;
	GetOwner()->GetWorldTimerManager().SetTimer(
		UnusedHandle, 
		this, 
		&UPlayerInterface::RecursiveTextScreenPlayPortrayal, 
		1.0f, 
		false
	);
	//	UnusedHandle,
	//	this,
	//	&UPlayerInterface::RecursiveTextScreenPlayPortrayal,
	//	1000,
	//	false
	//);

	//RecursiveTextScreenPlayPortrayal();
	//// For each row, get the UI to display it's narration or dialog line for some time
	//for (FScreenPlayEntry* entry : ScreenPlayEntries)
	//{
	//	if (entry->narration.Num() > 0) {
	//		playerDisplay->DisplayNarration(entry->narration[0]);
	//		FTimerHandle UnusedHandle;
	//		GetWorld()->GetTimerManager()->SetTimer(
	//			
	//		);
	//	}
	//	else if (entry->dialogLine.Num() > 0) {
	//		playerDisplay->DisplayDialogLine(entry->dialogLine[1]);
	//	}
	//}

	//
	// Message the caller that job has been completed.
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

