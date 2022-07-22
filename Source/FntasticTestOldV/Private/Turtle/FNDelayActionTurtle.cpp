// Fill out your copyright notice in the Description page of Project Settings.

#include "Turtle/FNDelayActionTurtle.h"
#include "Components/AudioComponent.h"

void AFNDelayActionTurtle::BeginPlay()
{
	Super::BeginPlay();

}

void AFNDelayActionTurtle::MoveActorToLocation(const float& DeltaTime)
{
	if (!StopMovement)
	{
		Super::MoveActorToLocation(DeltaTime);
	}
}

void AFNDelayActionTurtle::ActionExecuted()
{
	StopMovement = !StopMovement;
	if (AudioStepsComponent)
	{
		if (StopMovement)
			AudioStepsComponent->Stop();
		else
			AudioStepsComponent->Play();

	}

	GetWorldTimerManager().SetTimer(ActionTimerHandle, this, &AFNDelayActionTurtle::ActionExecuted, StopMovement ? TimeAction : TimeMovement, false);
}
