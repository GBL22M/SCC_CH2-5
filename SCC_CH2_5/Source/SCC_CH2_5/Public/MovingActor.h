#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class SCC_CH2_5_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;

public:	
	void Move(int stepIdx);
	int32_t Step();

	float Distance(FVector2D startPos, FVector2D endPos);
	int CreateEvent();

private:
	FVector2D mStartPosition;
	int32_t mEventCount;
	float mTotalDistance;
};
