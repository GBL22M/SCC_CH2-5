// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SCC_CH2_5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void TSN();
	void RandomSum();
	void RandomNumberGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
