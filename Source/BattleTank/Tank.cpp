// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Math/UnrealMathUtility.h"
//#include "TankBarrel.h"
//#include "Projectile.h"

//#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// no need to protect pointers as added at construction 
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);


	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tank died."))
		OnDeath.Broadcast();
	}
	

	return DamageToApply;
}


//void ATank::AimAt(FVector HitLocation)
//
//{
//	if (!TankAimingComponent) { return; }
//	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
//
//}

//void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
//{
//	TankAimingComponent->SetBarrelReference(BarrelToSet);
//	Barrel = BarrelToSet;
//}
//
//void ATank::SetTurretReference(UTankTurret * TurretToSet)
//{
//	TankAimingComponent->SetTurretReference(TurretToSet);
//}



//// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
	
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}


// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

