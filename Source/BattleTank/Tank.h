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

	

};
