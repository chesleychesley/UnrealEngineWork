

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealEngineWork/Collection/PickupCollectionBase.h"
#include "BatteryPickupCollection.generated.h"

UCLASS()
class UNREALENGINEWORK_API ABatteryPickupCollection : public APickupCollectionBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABatteryPickupCollection();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnPickupCollected_Implementation() override;

};
