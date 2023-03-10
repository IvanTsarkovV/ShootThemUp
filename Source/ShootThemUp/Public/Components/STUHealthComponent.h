// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "STUHealthComponent.generated.h"

class UCameraShakeBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USTUHealthComponent();

	FOnDeathSignature OnDeath;
	FOnHealthChangedSignature OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category="Health")
	bool IsDead() const { return FMath::IsNearlyZero(Health); }

	UFUNCTION(BlueprintCallable, Category="Health")
	float GetHealthPercent() const { return Health / MaxHealth; }

	float GetHealth() const { return Health; }

	bool TryToAddHealth(float HealthAmount);
	bool IsHealthFull() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(ClampMin="0.0", ClampMax="1000.0"))
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	bool AutoHealth = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(EditCondition="AutoHealth"))
	float HealthUpdateTime = 0.3f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(EditCondition="AutoHealth"))
	float HealthDelay = 3.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health", meta=(EditCondition="AutoHealth"))
	float HealthModifier = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="VFX")
	TSubclassOf<UCameraShakeBase> CameraShake;

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Health = 0.0f;
	FTimerHandle HealthTimerHandle;

	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
	                     AController* InstigatedBy, AActor* DamageCauser);

	void HealthUpdate();
	void SetHealth(float NewHealth);

	void PlayCameraShake();

	void Killed(AController* KillerController);
};
