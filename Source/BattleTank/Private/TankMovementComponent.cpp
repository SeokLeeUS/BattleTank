// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}



void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// no need to call super as we are replacing the functionality 
	//auto TankName = GetOwner()->GetName();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;

	IntendTurnRight(RightThrow);
	IntendMoveForward(ForwardThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString)




}



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	/*auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();*/
	//UE_LOG(LogTemp, Warning, TEXT("move forward"))
	if (!ensure(LeftTrack)) {return;}
	if (!ensure(RightTrack)){return;}
	UE_LOG(LogTemp, Warning, TEXT("throw: %f "), Throw)
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	/*auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();*/
	
	if (!ensure(LeftTrack && RightTrack)) { return; }
	
	UE_LOG(LogTemp, Warning, TEXT("throw: %f "), Throw)
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}