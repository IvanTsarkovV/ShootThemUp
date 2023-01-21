// Shoot Them Up Game. All Rights Reserved.


#include "Weapon/STUProjectile.h"
#include "Components/SphereComponent.h"

// Sets default values
ASTUProjectile::ASTUProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent->InitSphereRadius(5.0f);
	SetRootComponent(CollisionComponent);
}

// Called when the game starts or when spawned
void ASTUProjectile::BeginPlay()
{
	Super::BeginPlay();
}
