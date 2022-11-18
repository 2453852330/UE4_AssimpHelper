// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralMeshActor.h"
#include "ProceduralMeshComponent.h"



// Sets default values
AProceduralMeshActor::AProceduralMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PMC = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("PMC"));
	RootComponent = PMC;
}

// Called when the game starts or when spawned
void AProceduralMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
	CF_MakeMeshFromData();
}

// Called every frame
void AProceduralMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AProceduralMeshActor::CF_MakeMeshFromData()
{
	if (!PMC)
	{
		UE_LOG(LogTemp,Warning,TEXT("[ProceduralMeshActor][PMC component is not valid]"));
		return;
	}
	// clear old  data
	PMC->ClearAllMeshSections();
	
	PMC->CreateMeshSection(0,Vertex,Index,TArray<FVector>(),TArray<FVector2D>(),TArray<FColor>(),TArray<FProcMeshTangent>(),bMakeCollision);

	PMC->SetMaterial(0,MatShow);
}

void AProceduralMeshActor::CF_UpdateShadow(bool bEnable)
{
	if (PMC)
	{
		PMC->SetCastShadow(bEnable);
		PMC->bUseAsyncCooking = true;
	}
}

