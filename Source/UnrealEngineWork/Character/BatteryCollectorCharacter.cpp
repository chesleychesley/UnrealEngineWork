


#include "BatteryCollectorCharacter.h"


// Sets default values
ABatteryCollectorCharacter::ABatteryCollectorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));

	CollisionSphere->SetupAttachment(RootComponent);

	CollisionSphere->SetSphereRadius(200.0f);

}

// Called when the game starts or when spawned
void ABatteryCollectorCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryCollectorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABatteryCollectorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


