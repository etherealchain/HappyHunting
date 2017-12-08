// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveAround.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AMoveAround::BeginPlay() {
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), targetPoints);
	currentIndex = 0;
	GotoPoint();
}

void AMoveAround::GotoPoint() {
	if (currentIndex == targetPoints.Num()) {
		currentIndex = 0;
	}
	MoveToActor(Cast<ATargetPoint>(targetPoints[currentIndex]));
	currentIndex++;
}

void AMoveAround::OnMoveCompleted(FAIRequestID id, const FPathFollowingResult& result) {
	Super::OnMoveCompleted(id, result);
	GetWorldTimerManager().SetTimer(timerHandle, this, &AMoveAround::GotoPoint, 1.0f, false);
}