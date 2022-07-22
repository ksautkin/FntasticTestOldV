// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FNBaseTurtle.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class USoundCue;
class UAudioComponent;

UCLASS()
class FNTASTICTESTOLDV_API AFNBaseTurtle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFNBaseTurtle();
	// Called every frame
	virtual void Tick(float DeltaTime);
	// Setter/Getter Location
	void SetLocationToMove(const FVector& Location);
	FVector GetLocationToMove() const;
	// Setter/Getter Speed
	void SetSpeedTurtle(const float& Speed);
	float GetSpeedTurtle() const;
	// Check movement finished
	bool IsFinished() const;
	// Setter/Getter Direction
	void SetDirectionTurtle(const FVector& Direction);
	FVector GetDirectionTurtle() const;

private:
	// Location to move
	FVector LocationToMove;
	// Speed of turtle
	float SpeedTurtle;
	// Turtle reached location
	bool IsTurtleFinished = false;
	// Direction to location 
	FVector DirectionToLocation;

protected:
	// For showing actor on scene
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* MeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UAudioComponent* AudioStepsComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* SoundSteps;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Move actor to location 
	virtual void MoveActorToLocation(const float& DeltaTime);
};
