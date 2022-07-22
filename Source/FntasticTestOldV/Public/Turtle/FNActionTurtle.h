// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle/FNBaseTurtle.h"
#include "FNActionTurtle.generated.h"

UCLASS(Abstract)
class FNTASTICTESTOLDV_API AFNActionTurtle : public AFNBaseTurtle
{
	GENERATED_BODY()

private:
	// Timer off 
	bool IsTimerOff = false;

protected:
	// Timer for special turtil action
	UPROPERTY()
		FTimerHandle ActionTimerHandle;
	// Time for movement
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Timer")
		float TimeMovement = 1.0f;
	// Time for executing action
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Timer")
		float TimeAction = 0.30f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		virtual void ActionExecuted();
};