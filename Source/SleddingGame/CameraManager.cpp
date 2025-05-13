// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManager.h"

void ACameraManager::UpdateCamera(float DeltaTime)
{
}

ACameraManager::ACameraManager() : APlayerCameraManager()
{
	PrimaryActorTick.bCanEverTick = true;
}
