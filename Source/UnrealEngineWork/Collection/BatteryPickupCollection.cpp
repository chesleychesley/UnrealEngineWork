


#include "BatteryPickupCollection.h"


// Sets default values
ABatteryPickupCollection::ABatteryPickupCollection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABatteryPickupCollection::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryPickupCollection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABatteryPickupCollection::OnPickupCollected_Implementation()
{
	//base functionality
	Super::OnPickupCollected_Implementation();

	Destroy();
}



