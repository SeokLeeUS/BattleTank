// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	//auto ControlledTank = GetControlledTank();
	//auto PlayerTank = GetPlayerTank();
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	//if (ControlledTank != nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Pawn %s is possessed by AI controller"), *(GetPawn()->GetName()));
	//}

	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("PlayController does not possessing a tank"));
	//}

	//if (PlayerTank != nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("got it %s"), *(PlayerTank->GetName()));
	//}

	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("problem"));
	//}


}


void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp,Warning,TEXT("RECEIVED!"))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
		// Aim toward the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank -> GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}

	AimingComponent->Fire();
	//GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	//ControlledTank->Fire();
	// fire if ready
	//GetControlledTank()->Fire();
	MoveToActor(PlayerTank, AcceptanceRadius); // Todo check radius in cm 

	
	//UE_LOG(LogTemp, Warning, TEXT("Player controller is ticking"));
}

