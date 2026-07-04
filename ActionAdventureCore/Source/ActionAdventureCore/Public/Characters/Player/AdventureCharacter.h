// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AdventureCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class ACTIONADVENTURECORE_API AAdventureCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAdventureCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Camera", meta = (AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> CameraBoom{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Camera", meta = (AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> FollowCamera{ nullptr };

	// Locomotion calculation handlers called by input engine
	void HandleMovementInput(const FInputActionValue& Value);
	void HandleLookInput(const FInputActionValue& Value);

	// Advanced Enhanced Input asset configuration tracking hooks
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Input", meta = (AllowPrivateAccess="true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MovementAction{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction{ nullptr };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionAdventureCore|Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction{ nullptr };

};
