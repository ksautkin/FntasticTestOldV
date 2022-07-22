// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle/FTNest.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Turtle/FNBaseTurtle.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFTNest::AFTNest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());
}

void AFTNest::SpawnTurtle()
{
	FTransform Transform = GetTransform();
	Transform.SetLocation(Transform.GetLocation() + FVector(0, 0, 10));

	AFNBaseTurtle* Turtle = GetWorld()->SpawnActorDeferred<AFNBaseTurtle>(TurtleSpawnType, Transform);
	if (Turtle)
	{
		Turtle->SetSpeedTurtle(SpeedTurtle);
		Turtle->SetLocationToMove(LocationToMove);
		UGameplayStatics::FinishSpawningActor(Turtle, Transform);
	}
}