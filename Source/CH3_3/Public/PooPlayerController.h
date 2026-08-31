// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PooPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CH3_3_API APooPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	APooPlayerController();

	//IMC설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	//IA Move 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	//IA Look 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	//IA Jump 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	//IA Sprint 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	//BeginPlay 오버라이드
	virtual void BeginPlay() override;

};
