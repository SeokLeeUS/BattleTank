// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#define OUT

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller is ticking"));
}



void ATankPlayerController::BeginPlay()
{
	//auto ControlledTank = GetControlledTank();
	Super::BeginPlay();
	auto AimingComponent =GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);

	
	/*UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (ControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn %s"), *(GetPawn()->GetName()));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController does not possessing a tank"));
	}*/

}


//ATank* ATankPlayerController::GetControlledTank() const
//{
//	
//		//return Cast<ATank>(GetPawn());
//		return GetPawn();
//	
//	
//}

void ATankPlayerController::AimTowardCrosshair()
{
	//if (!ensure(GetControlledTank())){ return; }
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation; //

	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString())
		AimingComponent->AimAt(HitLocation);
	}
	
	// get world location if linetrace through crosshair
	// if it hits the landscape
		// tell controlled tank to aim at this point 
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	// find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	FVector WorldLocation;
	FVector WorldDirection;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	// "de-project" the screen position of the crosshair to a world direction
	// line trace along that look direction, and see what we hit (up to max range)
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	FVector LookDirection;


	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);
			   		 
	}
	
	//HitLocation = FVector(1.0);
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}



bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);


	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


