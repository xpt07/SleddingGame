// Fill out your copyright notice in the Description page of Project Settings.


#include "SledgeBase.h"

// Sets default values
ASledgeBase::ASledgeBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASledgeBase::ApplySteerTorque()
{
	FVector Torque = (SledgeMesh->GetUpVector() * sTorque) * yaw;
	
	SledgeMesh->AddTorqueInRadians(Torque);
}

void ASledgeBase::ApplyForwardForce()
{
	FVector Force = SledgeMesh->GetForwardVector() * LForce;
	if (isGrounded)
	{
		SledgeMesh->AddForce(Force);
	}
}

void ASledgeBase::ApplyAirControl()
{
	FVector Torque = (SledgeMesh->GetForwardVector() * sTorque) * roll;

	SledgeMesh->AddTorqueInRadians(Torque);

	Torque = (SledgeMesh->GetRightVector() * sTorque) * pitch;

	SledgeMesh->AddTorqueInRadians(Torque);
}

void ASledgeBase::ApplyDirectionalFriction(float otherFriction)
{
	FVector vel = SledgeMesh->GetComponentVelocity();
	FVector velDir = vel;
	velDir.Normalize();

	float frictionRatio = FMath::Abs( velDir.Dot(SledgeMesh->GetRightVector()));
	frictionRatio *= otherFriction;

	FVector friction = frictionRatio * vel * -1;
	frictionForce = friction;
	FVector forwardForce = SledgeMesh->GetForwardVector() * friction.Length() * 5.f;

	SledgeMesh->AddForce(friction, NAME_None, true);
	SledgeMesh->AddForce(forwardForce, NAME_None, false);
}

void ASledgeBase::ResetValues()
{
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;
	isGrounded = false;
}

void ASledgeBase::setStaticMesh(UStaticMeshComponent* mesh)
{
	SledgeMesh = mesh;
}

// Called when the game starts or when spawned
void ASledgeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASledgeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}