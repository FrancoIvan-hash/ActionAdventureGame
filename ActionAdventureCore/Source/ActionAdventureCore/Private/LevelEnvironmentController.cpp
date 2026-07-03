// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEnvironmentController.h"

// Sets default values
ALevelEnvironmentController::ALevelEnvironmentController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxAllowedWorldExtent = FVector(5000.f, 5000.f, 5000.f);
	HardKillThreshold = -2000.f;

}

// Called when the game starts or when spawned
void ALevelEnvironmentController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelEnvironmentController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelEnvironmentController::VerifyActorWorldBounds(AActor* ActorToVerify)
{
	if (!ActorToVerify) 
		return;

	FVector ActorLocation = ActorToVerify->GetActorLocation();

	if (ActorLocation.Z < HardKillThreshold)
		ActorToVerify->Destroy();
}

