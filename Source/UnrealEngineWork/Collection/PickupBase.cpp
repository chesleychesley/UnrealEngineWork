// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));

	MinSpawnDelay = .5f;
	MaxSpawnDelay = 5.0f;


}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();


	RandomSpawnDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &APickupBase::SpawnBatteryActor, RandomSpawnDelay, false);

}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector APickupBase::GetRandomSpawnPoint()
{
	const FVector SpawnOrigin = SpawnVolume->Bounds.Origin;
	const FVector SpawnLimit = SpawnVolume->Bounds.BoxExtent;
	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimit);
}

void APickupBase::SpawnBatteryActor()
{
	if (!ActorToSpawn)
	{
		return;
	}
	FRotator RandomRotation;
	RandomRotation.Yaw = FMath::RandRange(1, 3) * 360.0f;
	RandomRotation.Pitch = FMath::RandRange(1, 3) * 360.0f;
	RandomRotation.Roll = FMath::RandRange(1, 3) * 360.0f;
	
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.Instigator = GetInstigator();
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	if (!GetWorld()){return;}

	AMyActor* myActorSpawned = GetWorld()->SpawnActor<AMyActor>(ActorToSpawn, GetRandomSpawnPoint(), RandomRotation, Params);

	RandomSpawnDelay = FMath::RandRange(MinSpawnDelay, MaxSpawnDelay);
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &APickupBase::SpawnBatteryActor, RandomSpawnDelay, false);
}

