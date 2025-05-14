// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SledSound.generated.h"

class UAudioComponent;
class USoundWave;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SLEDDINGGAME_API USledSound : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USledSound();
	
	UAudioComponent* RockHitAudioComponent;
	UAudioComponent* TreeHitAudioComponent;
	UAudioComponent* WindAudioComponent;
	UAudioComponent* SlideAudioComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Sounds")
	void InitSoundPlayer(UAudioComponent* rockHitAudioComponent, UAudioComponent* treeHitAudioComponent,
		UAudioComponent* windAudioComponent, UAudioComponent* slideAudioComponent);

	UFUNCTION(BlueprintCallable, Category = "Sounds")
	void UpdateSounds(float speed, bool grounded);

	UFUNCTION(BlueprintCallable, Category = "Sounds")
	void PlayHitSounds(TArray<FString> tags);
};
