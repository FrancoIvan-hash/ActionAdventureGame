// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldArchitectureAnchor.h"

// Sets default values
AWorldArchitectureAnchor::AWorldArchitectureAnchor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AnchorIdentifier = TEXT("Default_Level_Zero_Anchor");

}

// Called when the game starts or when spawned
void AWorldArchitectureAnchor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldArchitectureAnchor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

