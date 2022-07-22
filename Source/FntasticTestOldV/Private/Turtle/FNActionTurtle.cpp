// Fill out your copyright notice in the Description page of Project Settings.

#include "Turtle/FNActionTurtle.h"

void AFNActionTurtle::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(ActionTimerHandle, this, &AFNActionTurtle::ActionExecuted, TimeMovement, false);
}

void AFNActionTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If actor reached location - timer off 
	if (!IsTimerOff && IsFinished())
	{
		IsTimerOff = true;
		GetWorldTimerManager().ClearTimer(ActionTimerHandle);
	}
}


void AFNActionTurtle::ActionExecuted()
{
}