#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PooCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class CH3_3_API APooCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APooCharacter();

	//카메라 컴퍼넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")	
	UCameraComponent* CameraComponent;
	//카메라 스프링 암 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComponent;

	//최대 체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth; //최대 체력

	//현재 체력
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth; //현재 체력

	//기본이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed; //기본 이동 속도

	//달리기 속도 배수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintMultiplier; //달리기 속도 배수
	
	//Move 인풋 액션 설정
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Move(const FInputActionValue& Value);

	//Look 인풋 액션 설정
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Look(const FInputActionValue& Value);

	//Jump 시작
	UFUNCTION(BlueprintCallable, Category = "Input")
	void JumpStart(const FInputActionValue& Value);

	//jump 끝
	void JumpEnd(const FInputActionValue& Value);

	//Sprint 시작
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SprintStart(const FInputActionValue& Value);

	//Sprint 끝
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SprintEnd(const FInputActionValue& Value);


protected:
	virtual void BeginPlay() override;

	float SprintSpeed; //달리기 속도	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
