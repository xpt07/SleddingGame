// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/Texture2D.h"
#include "SledgeBase.h"
#include "PathGenerator.generated.h"

UCLASS()
class SLEDDINGGAME_API APathGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	class UMaterialInstanceDynamic* SnowImprintShaderInstance;

	UPROPERTY()
	class UMaterialInstanceDynamic* TrailBlenderShaderInstance;

	UPROPERTY()
	FRotator CaptureOrientation;

	UPROPERTY()
	FVector CaptureDistanceFromOrigin;

	AActor* TerrainActor;
	FVector Origin;
	FVector TerrainExtent;
	float CaptureWidth;

	FVector2D GetUVFromWorld(FVector pos);

	void MakeImprint();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ASledgeBase* PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UTextureRenderTarget2D* ImprintRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UTextureRenderTarget2D* TerrainRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UTextureRenderTarget2D* TrailRenderTargetTemp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTextureRenderTarget2D* TrailRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialInterface* SnowImprintShader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialInterface* TrailBlenderShader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneCaptureComponent2D* FootprintCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneCaptureComponent2D* TerrainCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterialParameterCollection* MPC;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "snow")
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
