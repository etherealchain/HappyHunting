// Fill out your copyright notice in the Description page of Project Settings.

#include "Patrol.h"
#include "EngineUtils.h"

void APatrol::BeginPlay() {
	Super::BeginPlay();
	
	isStart = true;
	start = nullptr;
	end = nullptr;
}

void APatrol::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}

void APatrol::setPoints(AActor* s, AActor* e) {
	start = Cast<ATargetPoint>(s);
	end = Cast<ATargetPoint>(e);

	GotoPoint();
}

void APatrol::GotoPoint() {
	if (isStart) {
		MoveToActor(start);
		isStart = false;
	}
	else {
		MoveToActor(end);
		isStart = true;
	}
	
}

void APatrol::OnMoveCompleted(FAIRequestID id, const FPathFollowingResult& result) {
	Super::OnMoveCompleted(id, result);
	GetWorldTimerManager().SetTimer(timerHandle, this, &APatrol::GotoPoint, 5.0f, false);
}


