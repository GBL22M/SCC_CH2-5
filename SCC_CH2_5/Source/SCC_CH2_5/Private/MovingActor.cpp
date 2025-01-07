#include "MovingActor.h"

AMovingActor::AMovingActor()
	:mStartPosition({0,0})
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < 10; ++i)
	{
		Move();
	}
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovingActor::Move()
{
	int xStep = Step();
	int yStep = Step();
	mStartPosition.X += xStep;
	mStartPosition.Y += yStep;

	UE_LOG(LogTemp, Warning, TEXT("step (X: %d, Y: %d) | current position (X: %d , Y: %d)"),xStep, yStep, (int)mStartPosition.X, (int)mStartPosition.Y);
}

int32_t AMovingActor::Step()
{
	return FMath::RandRange(0, 1);
}

