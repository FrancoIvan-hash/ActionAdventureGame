// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/ProjectDiagnosticComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UProjectDiagnosticComponent::UProjectDiagnosticComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bHaltExecutionOnFailure = true;
	RequiredWorkspacePrefix = TEXT("BP_");
	
}


// Called when the game starts
void UProjectDiagnosticComponent::BeginPlay()
{
	Super::BeginPlay();

	// Automatically trigger the sanity audit when the game level initializes
	PerformWorkspaceSanityCheck();
	
}


// Called every frame
void UProjectDiagnosticComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UProjectDiagnosticComponent::PerformWorkspaceSanityCheck()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor)
	{
		UE_LOG(LogTemp, Error, TEXT("[Diagnostic] Failure: Component has no valid owner actor container."));
		return false;
	}

	FString OwnerName = OwnerActor->GetName();
	UE_LOG(LogTemp, Display, TEXT("[Diagnostic] Success: Initiating workspace validation for entity: %s"), *OwnerName);

	// Verify structural object mobility settings
	if (OwnerActor->IsRootComponentStatic())
	{
		UE_LOG(LogTemp, Warning, TEXT("[Diagnostic] Warning: %s is marked as Static. Dynamic systems may fail to alter its coordinates."), *OwnerName);
	}

	// Check for uninitialized identity states
	if (OwnerName.Contains(TEXT("NewBlueprint")))
	{
		UE_LOG(LogTemp, Error, TEXT("[Diagnostic} Failure: Asset retains default engine factory naming layout. Rename immediately"));

		if (bHaltExecutionOnFailure)
		{
			UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
		}

		return false;
	}

	UE_LOG(LogTemp, Display, TEXT("[Diagnostic] Success: Sanity check completed successfully. Workspace matches production standards."));
	return true;
}

