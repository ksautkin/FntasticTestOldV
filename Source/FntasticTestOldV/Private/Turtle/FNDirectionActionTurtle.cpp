// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle/FNDirectionActionTurtle.h"

void AFNDirectionActionTurtle::BeginPlay()
{
	Super::BeginPlay();

}

void AFNDirectionActionTurtle::MoveActorToLocation(const float& DeltaTime)
{
	if (IsDirectionChanged)
	{
		//  inverse direction 
		SetDirectionTurtle(GetDirectionTurtle() * -1);
	}
	Super::MoveActorToLocation(DeltaTime);
}

void AFNDirectionActionTurtle::ActionExecuted()
{
	IsDirectionChanged = !IsDirectionChanged;

	GetWorldTimerManager().SetTimer(ActionTimerHandle, this, &AFNDirectionActionTurtle::ActionExecuted, IsDirectionChanged ? TimeAction : TimeMovement, false);
}