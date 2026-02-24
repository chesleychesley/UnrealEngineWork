

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Components/SphereComponent.h"
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USphereComponent* GetSphereCollision() const { return CollisionSphere; }
	
};
