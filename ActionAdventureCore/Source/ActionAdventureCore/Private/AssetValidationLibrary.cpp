// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetValidationLibrary.h"

bool UAssetValidationLibrary::VerifyAssetNamingConvention(const FString& AssetName, const FString& ExpectedPrefix)
{
	if (AssetName.IsEmpty() || ExpectedPrefix.IsEmpty())
	{
		return false;
	}

	return AssetName.StartsWith(ExpectedPrefix);
}
