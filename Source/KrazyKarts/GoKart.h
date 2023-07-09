// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputMappingContext* DefaultMappingContext;

		/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* MoveAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		class UInputAction* RightAction;

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for movement input */
	void MoveForward(const FInputActionValue& Value);
	void StopMoving();

	void MoveRight(const FInputActionValue& Value);
	void StopTurn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//car mass
	UPROPERTY(EditAnywhere)
		float Mass = 1000;

	//The force applied to the car when the throttle is fully down 
	UPROPERTY(EditAnywhere)
		float MaxDrivingForce = 10000;

	// The number of degrees rotated per second at full control throw (degrees/s).
	UPROPERTY(EditAnywhere)
		float MinTurningRadius = 10;

	// Higher means more rolling resistance.
	UPROPERTY(EditAnywhere)
		float RollingResistanceCoefficient = 0.015;

	// Higher means more drag.
	UPROPERTY(EditAnywhere)
		float DragCoefficient = 16;

	float Throttle;

	FVector Velocity;

	float SteeringThrow;

	void ApplyRotation(float DeltaTime);
	void UpdateLocationFromVelocity(float DeltaTime);

	FVector GetAirResistance();
	FVector GetRollingResistance();
};
