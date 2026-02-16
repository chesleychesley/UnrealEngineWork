// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values 
//construction function
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;*/

	bIsActive = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool  AMyActor::IsPickupActive() const {
	return bIsActive;
}

void AMyActor::SetPickupIsActive(bool IsActive) {
	bIsActive = IsActive;
}

