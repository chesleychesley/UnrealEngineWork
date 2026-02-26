

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectionGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALENGINEWORK_API ABatteryCollectionGameMode : public AGameModeBase
{
	GENERATED_BODY()

public :
	ABatteryCollectionGameMode();

	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerAmounToWin() const;

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DecayAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float PowerAmounToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float PowerToWinMultiplier;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	TSubclassOf<class UUserWidget> MainHUDClass;

	UPROPERTY()
	class UUserWidget* ActiveWidget;
	
	virtual void BeginPlay() override;

public:
	void StartPowerLevelDecay();
};
