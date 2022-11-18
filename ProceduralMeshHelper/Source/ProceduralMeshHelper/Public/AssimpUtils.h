// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssimpUtils.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALMESHHELPER_API UAssimpUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable)
	static void CFL_Test(FString FileName,TArray<FVector> & Vertex,TArray<int32> & Indices);
};
