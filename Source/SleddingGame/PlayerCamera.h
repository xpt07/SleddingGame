// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCamera.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLEDDINGGAME_API UPlayerCamera : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCamera();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Rotation")
	float CameraRotationSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Rotation")
	float MinPitchAngle = -60.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Rotation")
	float MaxPitchAngle = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Fov")
	float MinFovValue = 70.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Fov")
	float MaxFovValue = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Fov")
	float MinFovSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Fov")
	float FovChangeRange = 2000.f;

	USpringArmComponent* CameraArm;
	UCameraComponent* Camera;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Camera Manager")
	void InitCamera(USpringArmComponent* newCameraArm, UCameraComponent* camera);

	UFUNCTION(BlueprintCallable, Category = "Camera Manager")
	void UpdateCamera(float speed);

	UFUNCTION(BlueprintCallable, Category = "Camera Manager")
	void OnRotationInput(FVector2D rotationInput);
};
