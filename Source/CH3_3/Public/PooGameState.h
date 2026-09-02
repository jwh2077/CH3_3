// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PooGameState.generated.h"

/**
 * 
 */
UCLASS()
class CH3_3_API APooGameState : public AGameState
{
	GENERATED_BODY()

public:

	APooGameState();

	//총 점수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game|Score")
	int32 Score;
	//스폰 코인 수
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game|Coin")
	int32 SpawnCoinCount;
	//먹은 코인 수
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game|Coin")
	int32 EatenCoinCount;
	//레벨 제한 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game|Time")
	float LevelTimeLimit;
	//현재 레벨
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game|Level")
	int32 CurrentLevelIndex;
	//최대 레벨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game|Level")
	int32 MaxLevel;
	//맵 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game|Level")
	TArray<FName> LevelMapNames;

	//레벨 타이머 헨들
	FTimerHandle LevelTimerHandle;
	//HUD업데이트 타이머	헨들
	FTimerHandle HUDUpdateTimerHandle;

	//점수 확인
	UFUNCTION(BlueprintCallable, Category = "Game|Score")
	int32 GetScore() const;
	//점수 증가
	UFUNCTION(BlueprintCallable, Category = "Game|Score")
	void AddScore(int32 ScoreToAdd);
	//게임오버
	UFUNCTION(BlueprintCallable, Category = "Game|State")
	void OnGameOver();

	//BeginPlaye 생성
	virtual void BeginPlay() override;
		
	//게임시작
	void StartLevel();
	//시간 종료
	void OnLevelTimeUp();
	//게임 종료
	void EndGame();
	//코인 카운트
	void OnCoinCollecte();
	//UI업데이트
	void UpDateHUD();
};
