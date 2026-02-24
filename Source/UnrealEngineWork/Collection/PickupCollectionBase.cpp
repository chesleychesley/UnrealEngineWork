// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupCollectionBase.h"

// Sets default values
APickupCollectionBase::APickupCollectionBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsActive = true;
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickupCollectionBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupCollectionBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool  APickupCollectionBase::IsPickupActive() const {
	return bIsActive;
}

void APickupCollectionBase::SetPickupIsActive(bool IsActive) {
	bIsActive = IsActive;
}


void APickupCollectionBase::OnPickupCollected_Implementation()
{
	const FString DebugString = GetName();
	UE_LOG(LogTemp, Warning, TEXT("We have picked up : %s "), *DebugString);

}


