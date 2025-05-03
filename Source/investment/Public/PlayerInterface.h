// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStructs.h"
#include "PlayerDisplayIO.h"
#include "PlayerInterface.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class INVESTMENT_API UPlayerInterface : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInterface();

	/// <summary>
	/// Work with the display facing the player to portray the screenplay.
	/// On completion, message back the caller that job has been done.
	/// In future, will need to resolve conflicts whether multiple portrayals have been requested.
	/// A mutex may be a good idea!
	/// </summary>
	/// <param name="rows"> Assume the structs are valid!</param>
	void DoTextScreenPlayPortrayal(TArray<FScreenPlayEntry*> rows, FCallBack delegate);
	void DoTextScreenPlayPortrayal(FText PortrayalNarration, FCallBack delegate);

	void ShowDecisionPointChoice(TArray<FDecisionPointAction*> dpActions, FListChoiceMade callBack);

	void ShowContextAction(FText ActionDeclaration, FListChoiceMade ActionHandler);

	void AddContextElement(FText ElementTag);

	void ClearContextActions();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite)
	UPlayerDisplayIO* playerDisplay;

	void TextScreenPlayPortrayal(TArray<FScreenPlayEntry*> ScreenPlayEntries, FCallBack callBack, int32 curInd);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SkipPortrayalTimer();

protected:
	FTimerHandle PortrayalTimerHandle;
	FTimerDelegate TimerDel;

private:
	void OnPortrayalFinished(FCallBack callBack);
};
