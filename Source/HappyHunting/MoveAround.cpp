// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveAround.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AMoveAround::BeginPlay() {
	Super::BeginPlay();
	GotoPoint();
}
void AMoveAround::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}

void AMoveAround::GotoPoint() {
	FNavLocation* result = new FNavLocation;
	while (!GetWorld()->GetNavigationSystem()->GetRandomReachablePointInRadius(GetNavAgentLocation(), 5000, *result)) {

	}
	MoveToLocation(result->Location);
	/*if (GetWorld()->GetNavigationSystem()->GetRandomReachablePointInRadius(GetNavAgentLocation(), 2000, *result)) {
		MoveToLocation(result->Location);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, result->Location.ToString());
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("2"));
	}*/
	//MoveToActor(Cast<ATargetPoint>(targetPoints[currentIndex]));

	
}

void AMoveAround::OnMoveCompleted(FAIRequestID id, const FPathFollowingResult& result) {
	Super::OnMoveCompleted(id, result);
	GetWorldTimerManager().SetTimer(timerHandle, this, &AMoveAround::GotoPoint, 3.0f, false);
}