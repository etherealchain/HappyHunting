// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Patrol.generated.h"

/**
 * 
 */

UCLASS()
class HAPPYHUNTING_API APatrol : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	void OnMoveCompleted(FAIRequestID id, const FPathFollowingResult& result) override;

	UFUNCTION(BlueprintCallable)
		void setPoints(AActor* s, AActor* e);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isChasing ;
	
private:

	void GotoPoint();

	FTimerHandle timerHandle;
	bool isStart;
	ATargetPoint* start;
	ATargetPoint* end;
};
