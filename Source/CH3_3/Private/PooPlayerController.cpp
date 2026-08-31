// Fill out your copyright notice in the Description page of Project Settings.


#include "PooPlayerController.h"
#include "EnhancedInputSubsystems.h"


APooPlayerController::APooPlayerController()
	//포인터 초기화
	: InputMappingContext(nullptr),
	MoveAction(nullptr),
	LookAction(nullptr),
	JumpAction(nullptr),
	SprintAction(nullptr)
{
}

void APooPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//로컬 플레이어 컨트롤러 불러오기
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		//로컬 플레이어의 서브시스템의 인풋 서브시스템 불러오기
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			//인풋 매핑 컨텍스트가 유효하면
			if (InputMappingContext)
			{
				//인풋 매핑 컨텍스트를 추가
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}
