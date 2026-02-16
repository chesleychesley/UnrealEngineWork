// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREALENGINEWORK_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	//gets the value of 
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsPickupActive() const;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetPickupIsActive(bool IsActive);

	void Test(bool value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
