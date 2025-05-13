// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UPlayerCamera::UPlayerCamera()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UPlayerCamera::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

// Called every frame
void UPlayerCamera::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerCamera::InitCamera(USpringArmComponent* NewCameraArm, UCameraComponent* camera)
{
	CameraArm = NewCameraArm;
	Camera = camera;

	if (Camera)
		Camera->SetFieldOfView(MinFovValue);
}

void UPlayerCamera::UpdateCamera(float speed)
{
	if (Camera)
	{
		float ratio = (speed - MinFovSpeed) / FovChangeRange;
		ratio = FMath::Clamp(ratio, 0.f, 1.f);
		float newFov = FMath::Lerp(MinFovValue, MaxFovValue, ratio);
		Camera->SetFieldOfView(newFov);
	}
}

void UPlayerCamera::OnRotationInput(FVector2D rotationInput)
{
	if (CameraArm)
	{
		FRotator newRotation = CameraArm->GetRelativeRotation();
		float deltaTime = GetWorld()->GetDeltaSeconds();

		// updated yaw
		newRotation.Yaw += rotationInput.X * CameraRotationSpeed * deltaTime;

		// update and clamp pitch
		newRotation.Pitch = FMath::Clamp(newRotation.Pitch + rotationInput.Y * CameraRotationSpeed * deltaTime, MinPitchAngle, MaxPitchAngle);

		// set the new rotation
		CameraArm->SetRelativeRotation(newRotation);
	}
}

