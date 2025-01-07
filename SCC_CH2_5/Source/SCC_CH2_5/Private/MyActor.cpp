// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

void TestUELogExamples()
{
    // 1. 일반 로그(Log) - 개발자가 디버깅을 위해 사용하는 기본 메시지
    UE_LOG(LogTemp, Log, TEXT("Game has started. Player has joined the game."));

    // 2. 중요 정보(Display) - 항상 표시되는 정보 메시지
    FString PlayerName = TEXT("Player1");
    UE_LOG(LogTemp, Display, TEXT("Welcome, %s! Enjoy the game."), *PlayerName);

    // 3. 경고(Warning) - 잠재적 문제가 있을 때 경고를 출력
    int PlayerHealth = 50;
    if (PlayerHealth < 100)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player health is below maximum: %d"), PlayerHealth);
    }

    // 4. 오류(Error) - 실행에 영향을 줄 수 있는 문제
    int AmmoCount = 0;
    if (AmmoCount == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("No ammo left! Player cannot shoot."));
    }

    // 5. 문자열 결합 - 다양한 데이터를 한 메시지로 출력
    int Score = 150;
    int TimeLeft = 120;
    UE_LOG(LogTemp, Log, TEXT("Score: %d, Time Left: %d seconds."), Score, TimeLeft);

    // 6. 부동소수점(Floating Point) 값 출력
    float PlayerSpeed = 325.5f;
    UE_LOG(LogTemp, Display, TEXT("Player speed: %.2f units/sec"), PlayerSpeed);

    // 7. 여러 심각도 사용 - 게임 상태에 따라 로그를 구분
    bool bIsPaused = true;
    if (bIsPaused)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game is currently paused."));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Game is running normally."));
    }

    // 8. 디버깅용 메시지 (Developer Note)
    UE_LOG(LogTemp, Display, TEXT("This message is for developers to debug the game state."));
}

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//RandomSum();
    //TestUELogExamples();
    RandomNumberGenerator();
}

void AMyActor::TSN()
{
	int32_t Start = 1;
	int32_t End = 30;

	for (int32_t i = Start; i <= End; ++i)
	{
		FString Number = FString::FromInt(i); //숫자를 문자열로
		bool bIsClap = false;

		for (TCHAR Char : Number)
		{
			if (Char == '3' || Char == '6' || Char == '9')
			{
				bIsClap = true;
				break;
			}
		}

		if (bIsClap)
		{
			UE_LOG(LogTemp, Warning, TEXT("Clap"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%d"), i);
		}
	}
}

void AMyActor::RandomSum()
{
	int MinValue = 1;
	int MaxValue = 100;

	int RandNum1 = FMath::RandRange(MinValue, MaxValue);
	int RandNum2 = FMath::RandRange(MinValue, MaxValue);
	int RandNum3 = FMath::RandRange(MinValue, MaxValue);

	int Sum = RandNum1 + RandNum2 + RandNum3;

	UE_LOG(LogTemp, Warning, TEXT("Random Numbers %d %d %d"), RandNum1, RandNum2, RandNum3);
	UE_LOG(LogTemp, Warning, TEXT("Sum %d"), Sum);
}

void AMyActor::RandomNumberGenerator()
{
    int32 MinValue = 1;
    int32 MaxValue = 45;

    TArray<int32> Array;

    while (Array.Num() < 6)
    {
        int RandomNumber = FMath::RandRange(MinValue, MaxValue);

        if (!Array.Contains(RandomNumber))
        {
            Array.Push(RandomNumber);
        }
    }
    Array.Sort();

    FString LottoNumberStr;
    for (int32 num : Array)
    {
        LottoNumberStr += FString::FromInt(num) + TEXT(", ");
    }
    LottoNumberStr.RemoveFromEnd(TEXT(", "));

    UE_LOG(LogTemp, Warning, TEXT("%s"), *LottoNumberStr);
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *LottoNumberStr));
    }
}
