// Shoot Them Up Game. All Rights Reserved.

#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController()
{
	RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("STURespawnComponent");
}

// void ASTUPlayerController::OnPossess(APawn* InPawn)
// {
// 	Super::OnPossess(InPawn);
//
// 	OnNewPawn.Broadcast(InPawn);
// }
