// Fill out your copyright notice in the Description page of Project Settings.


#include "SledgeBase.h"

// Sets default values
ASledgeBase::ASledgeBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

UStaticMeshComponent* ASledgeBase::GetStaticMesh()
{
	return SledgeMesh;
}

