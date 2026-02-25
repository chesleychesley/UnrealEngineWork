

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
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power")
	float DecayAmount;
	
	virtual void BeginPlay() override;

public:
	void StartPowerLevelDecay();
};
