#include "AccessUtils.h"

UPlayerInterface* GetPlayerInterface(UWorld* world)
{
	APlayerController* playerControl = UGameplayStatics::GetPlayerController(world, 0);
	return Cast<UPlayerInterface>(playerControl->GetComponentByClass(UPlayerInterface::StaticClass()));
}
