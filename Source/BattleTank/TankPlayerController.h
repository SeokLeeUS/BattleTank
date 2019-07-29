// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */


class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:

	//
	//UFUNCTION(BlueprintCallable,Category = "Setup")
	//ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimComRef);

public:
	

	

	virtual void BeginPlay() override;

	// start the tank moving the barrel so that a shot would it hit hwere
	// the crosshair 
	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector OUT & HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

private:

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.33333;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPawn(APawn * InPawn);

	UFUNCTION()
	void OnPossessedTankDeath();

	
};
