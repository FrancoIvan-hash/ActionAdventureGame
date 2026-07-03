// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetValidationLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONADVENTURECORE_API UAssetValidationLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "ActionAdventureCore|Validation")
	static bool VerifyAssetNamingConvention(const FString& AssetName, const FString& ExpectedPrefix);
	
};
