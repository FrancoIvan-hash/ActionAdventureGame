// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldArchitectureAnchor.generated.h"

UCLASS()
class ACTIONADVENTURECORE_API AWorldArchitectureAnchor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldArchitectureAnchor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Architecture", meta=(AllowPrivateAccess="true"))
	FString AnchorIdentifier{""};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

};
