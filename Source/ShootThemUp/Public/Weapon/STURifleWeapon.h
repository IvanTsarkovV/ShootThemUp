// Shoot Them Up Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;
class UNiagaraComponent;

UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

public:
	ASTURifleWeapon();
	
	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	float TimeBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	float DamageAmount = 10.0f;

	UPROPERTY(VisibleAnywhere, Category="VFX")
	USTUWeaponFXComponent* WeaponFXComponent;

	virtual void BeginPlay() override;
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

private:
	FTimerHandle ShotTimerHandle;

	UPROPERTY()
	UNiagaraComponent* MuzzleFXComponent;
	
	void MakeDamage(const FHitResult& HitResult);
	void InitMuzzleFX();
	void SetMuzzleFXVisibility(float Visible);
};
