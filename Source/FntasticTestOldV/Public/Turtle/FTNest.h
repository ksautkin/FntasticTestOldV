// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FTNest.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class AFNBaseTurtle;

UCLASS()
class FNTASTICTESTOLDV_API AFTNest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFTNest();
	// Spawn turtle
	UFUNCTION(BlueprintCallable)
	void SpawnTurtle();

protected:
	// Type of actor to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<AFNBaseTurtle> TurtleSpawnType;
	// For showing actor on scene
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	// Location to move
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector LocationToMove;
	// Speed of turtle
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SpeedTurtle = 10.0f;
};
