// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "CameraManager.generated.h"

/**
 * 
 */
UCLASS()
class SLEDDINGGAME_API ACameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere,Category = "Camera")
	float CameraFollowSpeed = 0.5f;

private:
	virtual void UpdateCamera(float DeltaTime) override;

public:
	ACameraManager();
};
