// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProjectDiagnosticComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONADVENTURECORE_API UProjectDiagnosticComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectDiagnosticComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "ActionAdventureCore|Diagnostics")
	bool PerformWorkspaceSanityCheck();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventure|Diagnostics")
	bool bHaltExecutionOnFailure{ true };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventure|Diagnostics")
	FString RequiredWorkspacePrefix{TEXT("")};

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
};
