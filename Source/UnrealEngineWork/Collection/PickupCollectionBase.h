// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupCollectionBase.generated.h"

UCLASS()
class UNREALENGINEWORK_API APickupCollectionBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupCollectionBase();

	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsPickupActive() const;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetPickupIsActive(bool NewActiveState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive;

#pragma region COMPONENTS
	UPROPERTY(EditDefaultsOnly, Category = "Component")
	UStaticMeshComponent* PickupMesh;

#pragma endregion


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void OnPickupCollected();

};
