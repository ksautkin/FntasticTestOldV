// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle/FNBaseTurtle.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

// Sets default values
AFNBaseTurtle::AFNBaseTurtle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AFNBaseTurtle::BeginPlay()
{
	Super::BeginPlay();

	// attache audio component to actor 
	AudioStepsComponent = UGameplayStatics::SpawnSoundAttached(SoundSteps, SceneComponent, NAME_None, GetActorLocation(), GetActorRotation());
}

void AFNBaseTurtle::MoveActorToLocation(const float& DeltaTime)
{
	AddActorWorldOffset(DeltaTime * SpeedTurtle * DirectionToLocation);
}

// Called every frame
void AFNBaseTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moving until it is near destination location
	if (!IsTurtleFinished)
	{
		if (AudioStepsComponent && !AudioStepsComponent->IsPlaying())
			AudioStepsComponent->Play();
		IsTurtleFinished = FVector::PointsAreNear(GetActorLocation(), LocationToMove, 1.0f);
		DirectionToLocation = UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(), LocationToMove);

		MoveActorToLocation(DeltaTime);
	}
	else
	{
		if (AudioStepsComponent && AudioStepsComponent->IsPlaying())
			AudioStepsComponent->Stop();
	}
}

void AFNBaseTurtle::SetLocationToMove(const FVector& Location)
{
	LocationToMove = Location;
}

FVector AFNBaseTurtle::GetLocationToMove() const
{
	return LocationToMove;
}

void AFNBaseTurtle::SetSpeedTurtle(const float& Speed)
{
	SpeedTurtle = Speed;
}

float AFNBaseTurtle::GetSpeedTurtle() const
{
	return SpeedTurtle;
}

bool AFNBaseTurtle::IsFinished() const
{
	return IsTurtleFinished;
}

void AFNBaseTurtle::SetDirectionTurtle(const FVector& Direction)
{
	DirectionToLocation = Direction;
}
FVector AFNBaseTurtle::GetDirectionTurtle() const
{
	return DirectionToLocation;
}

