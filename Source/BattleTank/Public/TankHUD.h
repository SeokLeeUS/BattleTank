// Copyright Seok Lee 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TankHUD.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankHUD : public AHUD
{
	GENERATED_BODY()


public:

	ATankHUD();
	
protected:

	/*The start location of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
		FVector2D RadarStartLocation = FVector2D(0.9f, 0.2f);

	/*The radius of our radar*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float RadarRadius = 100.f;

	UPROPERTY(EditAnywhere, Category = Radar)
		float DegreeStep = 0.25f;

	/*The pixel size of the drawable radar actors*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float DrawPixelSize = 5.f;

	/*The distance scale of the radar actors*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float RadarDistanceScale = 25.f;



	virtual void DrawHUD() override;

	/*Converts the given actors' location to local (based on our character)*/
	FVector2D ConvertWorldLocationToLocal(AActor* ActorToPlace);

	

private:
		/*Returns the center of the radar as a 2d vector*/
	FVector2D GetRadarCenterPosition();
	/*Draws the radar*/
	void DrawRadar();

	void DrawPlayerInRadar();

	void PerformRadarRaycast();

	/*Draws the raycasted actors in our radar*/
	void DrawRaycastedActors();

	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;


protected:

	/*Sphere height and radius for our raycast*/
	UPROPERTY(EditAnywhere, Category = Radar)
		float SphereHeight = 200.f;

	UPROPERTY(EditAnywhere, Category = Radar)
		float SphereRadius = 2750.f;

	/*Holds a reference to every actor we are currently drawing in our radar*/
	TArray<AActor*> RadarActors;
	
};
