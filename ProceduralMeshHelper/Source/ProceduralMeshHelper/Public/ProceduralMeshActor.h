// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshActor.generated.h"

UCLASS()
class PROCEDURALMESHHELPER_API AProceduralMeshActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralMeshActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY()
	class UProceduralMeshComponent * PMC = nullptr;

	UPROPERTY(BlueprintReadWrite,meta = (ExposeOnSpawn = true))
	UMaterialInterface* MatShow = nullptr;

	UPROPERTY(BlueprintReadWrite,meta = (ExposeOnSpawn = true))
	TArray<int32> Index;
	UPROPERTY(BlueprintReadWrite,meta = (ExposeOnSpawn = true))
	TArray<FVector> Vertex;
	UPROPERTY(BlueprintReadWrite,meta = (ExposeOnSpawn = true))
	bool bMakeCollision;

	void CF_MakeMeshFromData();

	UFUNCTION(BlueprintCallable)
	void CF_UpdateShadow(bool bEnable);
};
