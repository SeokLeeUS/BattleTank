// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "TankAimingComponent.h"
//#include "TankMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"
#include "Tank.generated.h"

//class UTankBarrel;
//class UTankTurret;
//class AProjectile;
//class UTankMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	//void AimAt(FVector HitLocation);
	//
	//UFUNCTION(BlueprintCallable, Category = Setup)
	//void SetBarrelReference(UTankBarrel* BarrelToSet);

	//UFUNCTION(BlueprintCallable, Category = Setup)
	//void SetTurretReference(UTankTurret* TurretToSet);
	// called by the engine when actor damage is dealt
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;


	FTankDelegate OnDeath;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(BlueprintReadOnly)
	//UTankAimingComponent * TankAimingComponent = nullptr;

	//UPROPERTY(BlueprintReadOnly)
	//UTankMovementComponent * TankMovementComponent = nullptr;

public:	

	// Called to bind functionality to input
	/*virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;*/
	//Reutnr current health as a percentage of starting health, between 0 and 1
	UFUNCTION (BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;

};
