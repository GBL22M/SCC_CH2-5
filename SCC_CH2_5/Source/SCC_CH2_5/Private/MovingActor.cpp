#include "MovingActor.h"

AMovingActor::AMovingActor()
	:mStartPosition({ 0,0 })
	, mEventCount(0)
	, mTotalDistance(0)
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 10; ++i)
	{
		int eventFlag = CreateEvent();
		Move(i);

		if (eventFlag == 1)
		{
			UE_LOG(LogTemp, Log, TEXT("Event Occurs!"));
			mEventCount++;
		}
		if (eventFlag == 0)
			UE_LOG(LogTemp, Log, TEXT("Nothing Happened"));

	}

	UE_LOG(LogTemp, Log, TEXT("Total Distance : %f, Total Event Count: %d"), mTotalDistance, mEventCount);
}


void AMovingActor::Move(int stepIdx)
{
	int xStep = Step();
	int yStep = Step();

	FVector2D beforeMove = mStartPosition;
	mStartPosition.X += xStep;
	mStartPosition.Y += yStep;
	float stepDistance = Distance(beforeMove, mStartPosition);

	UE_LOG(LogTemp, Log, TEXT("%d ) step (X: %d, Y: %d) | current position (X: %d , Y: %d)"),
		stepIdx + 1, xStep, yStep, (int)mStartPosition.X, (int)mStartPosition.Y);
	UE_LOG(LogTemp, Log, TEXT("move distance: %f"), stepDistance);
	mTotalDistance += stepDistance;
}

int32_t AMovingActor::Step()
{
	return FMath::RandRange(0, 1);
}

float AMovingActor::Distance(FVector2D startPos, FVector2D endPos)
{
	float resultDistance = sqrt((startPos.X - endPos.X) * (startPos.X - endPos.X) + (startPos.Y - endPos.Y) * (startPos.Y - endPos.Y));

	return resultDistance;
}

int AMovingActor::CreateEvent()
{
	return FMath::RandRange(0, 1);
}