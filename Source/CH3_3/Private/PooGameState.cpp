// Fill out your copyright notice in the Description page of Project Settings.


#include "PooGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"


APooGameState::APooGameState()
{
	//변수 초기화
	Score = 0;
	//스폰 코인 수 초기화
	SpawnCoinCount = 0;
	//먹은 코인 수 초기화
	EatenCoinCount = 0;
	//레벨 제한 시간 초기화
	LevelTimeLimit = 0.0f;
	//현재 레벨 초기화
	CurrentLevelIndex = 0;
	//최대 레벨 초기화
	MaxLevel = 3;
}

void APooGameState::BeginPlay()
{
	Super::BeginPlay();

	FString CurrentMapName = GetWorld()->GetMapName();
	if (!CurrentMapName.Contains(TEXT("MenuLevel")))
	{
		StartLevel();
	}

	GetWorldTimerManager().SetTimer(
		HUDUpdateTimerHandle,
		this,
		&APooGameState::UpDateHUD,
		0.1f,
		true
	);
}

void APooGameState::StartLevel()
{
}

void APooGameState::OnLevelTimeUp()
{
}

void APooGameState::EndGame()
{
}

void APooGameState::OnCoinCollecte()
{
}

void APooGameState::UpDateHUD()
{
}

void APooGameState::OnGameOver()
{
}

void APooGameState::AddScore(int32 ScoreToAdd)
{
}

int32 APooGameState::GetScore() const
{
	return Score;
}