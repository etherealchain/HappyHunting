// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine.h"
#include "MoveAround.generated.h"

/**
 * 
 */
UCLASS()
class HAPPYHUNTING_API AMoveAround : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	void OnMoveCompleted(FAIRequestID id, const FPathFollowingResult& result) override;

private:
		UFUNCTION()
		void GotoPoint();

		FTimerHandle timerHandle;
	
};
