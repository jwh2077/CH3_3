// Fill out your copyright notice in the Description page of Project Settings.


#include "PooGameMode.h"
#include "PooCharacter.h"
#include "PooGameState.h"

APooGameMode::APooGameMode()
{
	//기본 Pawn 클래스 설정
	DefaultPawnClass = APooCharacter::StaticClass();
	//컨트롤러 클래스 설정
	PlayerControllerClass = APlayerController::StaticClass();
	//게임 상태 클래스 설정
	GameStateClass = APooGameState::StaticClass();
}
