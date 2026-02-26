


#include "BatteryCollectionGameMode.h"
#include "UnrealEngineWork/Character/BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"



ABatteryCollectionGameMode::ABatteryCollectionGameMode()
{
	DelayTime = .2f;
	DecayAmount = 50.0f;
	PowerToWinMultiplier = 1.5f;

}

float ABatteryCollectionGameMode::GetPowerAmounToWin() const
{
	return PowerAmounToWin;
}

void ABatteryCollectionGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle PowerDecayTimeHandle;

	GetWorld()->GetTimerManager().SetTimer(PowerDecayTimeHandle, this,&ABatteryCollectionGameMode::StartPowerLevelDecay, DelayTime, true);

	ABatteryCollectorCharacter* PlayerCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (PlayerCharacter)
	{
		PowerAmounToWin = PlayerCharacter->GetBasePowerLevel() * PowerToWinMultiplier;
	}

	if (MainHUDClass) {
		ActiveWidget = CreateWidget<UUserWidget>(GetWorld(),MainHUDClass);
	}
}

void ABatteryCollectionGameMode::StartPowerLevelDecay()
{
	//get a reference to our player class
	ABatteryCollectorCharacter* PlayerCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
	if (PlayerCharacter && PlayerCharacter->GetCurrentPowerLevel()>0.0f  )
	{
		PlayerCharacter->UpdateCurrentPowerLevel(-DecayAmount);
	}
	//call the function that updates power level


}
