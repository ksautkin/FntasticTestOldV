// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle/FNActionTurtle.h"
#include "FNDirectionActionTurtle.generated.h"

UCLASS()
class FNTASTICTESTOLDV_API AFNDirectionActionTurtle : public AFNActionTurtle
{
	GENERATED_BODY()

private:
	// Change direction to location
	bool IsDirectionChanged = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Move actor to location 
	virtual void MoveActorToLocation(const float& DeltaTime) override;
	virtual void ActionExecuted() override;

};