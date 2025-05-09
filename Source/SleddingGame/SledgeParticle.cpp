// Fill out your copyright notice in the Description page of Project Settings.


#include "SledgeParticle.h"
#include "NiagaraComponent.h"

// Sets default values for this component's properties
USledgeParticle::USledgeParticle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	TotalBursts = 0;
	IsBurstActive = false;
	// ...
}


// Called when the game starts
void USledgeParticle::BeginPlay()
{
	Super::BeginPlay();

	TotalBursts = Bursts.Num();
	SetBursts(false);

	if (SpeedLines)
		SpeedLines->SetActive(false);
}

void USledgeParticle::SetParticleReferences(TArray<UNiagaraComponent*> bursts, UNiagaraComponent* speedLines)
{
	Bursts = bursts;
	SpeedLines = speedLines;
}

void USledgeParticle::SetParticlesActive(bool isGrounded, float speed)
{
	bool isMinSpeedReached = speed > minSpeedForParticles;
	if (SpeedLines)
		SpeedLines->SetActive(isMinSpeedReached);
	SetBursts(isGrounded && isMinSpeedReached);
}

void USledgeParticle::SetBursts(bool value)
{
	if (IsBurstActive == value)
		return;

	for (UNiagaraComponent* burst : Bursts)
		burst->SetActive(value);
	IsBurstActive = value;
}

