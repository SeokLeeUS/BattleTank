// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	//OnComponentHit
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("hit "))
	//DriveTrack();
	//ApplySidewaysForce();
	//CurrentThrottle = 0;

}



void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)

{
	
	//ApplySidewaysForce();

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = SlippageSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	//CorrectionForce = FVector(0); 
	TankRoot->AddForce(CorrectionForce);

}

void UTankTrack::ApplySidewaysForce()
{
	//Super::TickComponent();
	//UE_LOG(LogTemp, Warning, TEXT("track ticking"))
	/*auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()-> GetDeltaSeconds();
	auto CorrectionAcceleration = SlippageSpeed / DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);*/
}

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s thrrotle: %f "), *Name, Throttle)

		// TODO clmap acutal throttle value so player can't over drive
	//DriveTrack(Throttle);
	//CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1,1);
	//UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f "), *Name, Throttle)

	float multiple = 1;
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce*multiple;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());   //GetOwner means TankTrack
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

} 

void UTankTrack::DriveTrack()
{
	//float multiple = 1;
	//auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce*multiple;
	//auto ForceLocation = GetComponentLocation();
	//auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());   //GetOwner means TankTrack
	//TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
