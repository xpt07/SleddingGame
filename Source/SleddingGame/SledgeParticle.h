// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SledgeParticle.generated.h"

class UNiagaraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLEDDINGGAME_API USledgeParticle : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SledgeParticle")
	float minSpeedForParticles = 100.f;

	TArray<UNiagaraComponent*> Bursts;
	unsigned int TotalBursts;
	bool IsBurstActive;
	UNiagaraComponent* SpeedLines;

	// Sets default values for this component's properties
	USledgeParticle();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category = "SledgeParticle")
	void SetParticleReferences(TArray<UNiagaraComponent*> bursts, UNiagaraComponent* speedLines);

	UFUNCTION(BlueprintCallable, Category = "SledgeParticle")
	void SetParticlesActive(bool isGrounded, float speed);

	void SetBursts(bool value);
};
