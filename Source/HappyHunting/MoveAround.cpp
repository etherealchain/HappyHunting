// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveAround.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AMoveAround::BeginPlay() {
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), targetPoints);
	GotoPoint();
}
void AMoveAround::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, GetNavAgentLocation().ToString());
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