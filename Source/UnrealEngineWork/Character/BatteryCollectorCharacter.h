

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealEngineWork/Collection/PickupCollectionBase.h"
#include "UnrealEngineWork/Collection/BatteryPickupCollection.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BatteryCollectorCharacter.generated.h"

UCLASS()
class UNREALENGINEWORK_API ABatteryCollectorCharacter : public ACharacter
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"));
	class USphereComponent* CollisionSphere;

public:
	// Sets default values for this character's properties
	ABatteryCollectorCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CollectPickups();

	virtual void OnConstruction(const FTransform& Transform) override;


#pragma region POWERLEVEL

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Power");
	float BasePowerLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Power");
	float BaseSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Power");
	float SpeedMultiplier;

	UPROPERTY(VisibleAnywhere, Category = "Power");
	float CurrentPowerLevel;

	UPROPERTY(BlueprintReadWrite, Category = "Power|VFX")
	UMaterialInstanceDynamic* PowerLevelDynamicMaterial;

	UFUNCTION(BlueprintCallable )
	void UpdatePlayerMaterialColor();

public:
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetBasePowerLevel();


	UFUNCTION(BlueprintPure, Category = "Power")
	float GetCurrentPowerLevel();

	UFUNCTION(BlueprintCallable, Category = "Power")
	void UpdateCurrentPowerLevel(float increasement);
#pragma endregion

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USphereComponent* GetSphereCollision() const { return CollisionSphere; }
	
};
