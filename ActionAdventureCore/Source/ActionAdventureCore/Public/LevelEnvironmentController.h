// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelEnvironmentController.generated.h"

UCLASS()
class ACTIONADVENTURECORE_API ALevelEnvironmentController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelEnvironmentController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "ActionAdventureCore|Environment")
	void VerifyActorWorldBounds(AActor* ActorToVerify);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Environment", meta = (AllowPrivateAccess="true"))
	FVector MaxAllowedWorldExtent{ FVector::ZeroVector };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Environment", meta = (AllowPrivateAccess = "true"))
	float HardKillThreshold{ 0.0f };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
