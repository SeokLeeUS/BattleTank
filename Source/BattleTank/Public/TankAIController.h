// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "SetUp") // consider edit default only 
	float AcceptaceRadius = 8000;

	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	//How close can the AI tank get
	float AcceptanceRadius = 3000;
	
};
