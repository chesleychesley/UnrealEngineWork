


#include "BatteryCollectorCharacter.h"



// Sets default values
ABatteryCollectorCharacter::ABatteryCollectorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));

	CollisionSphere->SetupAttachment(RootComponent);

	CollisionSphere->SetSphereRadius(200.0f);

	BasePowerLevel = 2500.0f;
	CurrentPowerLevel = BasePowerLevel;

	BaseSpeed = 10.0f;
	SpeedMultiplier = .65f;
}

// Called when the game starts or when spawned
void ABatteryCollectorCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABatteryCollectorCharacter::CollectPickups()
{
	//create an array to put our overlapped actors in 
	TArray<AActor*> OverlappedActors;

	float cachedPowerLevel = .0f;

	//fill this array by getting the overlapped actors in our collection sphere
	CollisionSphere->GetOverlappingActors(OverlappedActors);

	//iterate over the array and cast the actor we find
	for (int index = 0; index < OverlappedActors.Num();++index)
	{
		APickupCollectionBase* OverlappedActor = Cast<APickupCollectionBase>(OverlappedActors[index]);

		//if that actor found is valid and its active and its not about to be destroyed then we call the OnCollected() Function on it
		if (OverlappedActor && OverlappedActor->IsPickupActive() && !OverlappedActor->IsPendingKillEnabled())
		{
			OverlappedActor->OnPickupCollected();

			ABatteryPickupCollection* Battery = Cast<ABatteryPickupCollection>(OverlappedActor);
			if (Battery){
				cachedPowerLevel += Battery->GetBatteryChargeAmount();


			}

			OverlappedActor->SetPickupIsActive(false);

			
		}

	}


	if (cachedPowerLevel > .0f) {
		UpdateCurrentPowerLevel(cachedPowerLevel);
	}
}

void ABatteryCollectorCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UMaterialInterface* MaterialToEdit = GetMesh()->GetMaterial(0);

	PowerLevelDynamicMaterial = UMaterialInstanceDynamic::Create(MaterialToEdit, this);

	if(!PowerLevelDynamicMaterial) return;
	GetMesh()->SetMaterial(0, PowerLevelDynamicMaterial);
}

void ABatteryCollectorCharacter::UpdatePlayerMaterialColor()
{
	FLinearColor FinalColor;
	

	//get initial and current power level create a ratio
	const float alpha = GetCurrentPowerLevel()/ GetBasePowerLevel();

	FinalColor = FLinearColor::LerpUsingHSV(FLinearColor::White, FLinearColor::Red, alpha);
	//get material set a vector parameter
	PowerLevelDynamicMaterial->SetVectorParameterValue("BodyColor", FinalColor);

	
}

float ABatteryCollectorCharacter::GetBasePowerLevel()
{
	return BasePowerLevel;
}

float ABatteryCollectorCharacter::GetCurrentPowerLevel()
{
	return CurrentPowerLevel;
}

void ABatteryCollectorCharacter::UpdateCurrentPowerLevel(float increasement)
{
	CurrentPowerLevel += increasement;

	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed + (SpeedMultiplier * CurrentPowerLevel);
	
	UpdatePlayerMaterialColor();

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

	PlayerInputComponent->BindAction("Collect",IE_Pressed, this, &ABatteryCollectorCharacter::CollectPickups);
}


