// Fill out your copyright notice in the Description page of Project Settings.


#include "PooCharacter.h"
#include "PooPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/TextBlock.h"

// Sets default values
APooCharacter::APooCharacter()
{
	//스프링 암 컴포넌트 생성
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//스프링 암 컴퍼넌트를 루트에 부착
	SpringArmComponent->SetupAttachment(RootComponent);
	//스프링 암 컴퍼넌트 길이 설정
	SpringArmComponent->TargetArmLength = 300.0f;
	//스프링 암 컴포넌트 회전값을 컨트롤러 회전값에 맞춤
	SpringArmComponent->bUsePawnControlRotation = true;

	//카메라 컴포넌트 생성
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	//카메라 컴포넌트를 스프링 암 컴포넌트 끝에 부착
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	//카메라 컴퍼넌트 회전값은 컨트롤러 회전값에 맞추지 않음
	CameraComponent->bUsePawnControlRotation = false;
	
	//최대 체력 설정
	MaxHealth = 100.0f;
	//현재 체력 설정
	CurrentHealth = MaxHealth;
	
	//기본 이동 속도 설정
	WalkSpeed = 600.0f;

	//캐릭터 이동 속도 적용
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

	//달리기 속도 배수 설정
	SprintMultiplier = 3.0f;


	PrimaryActorTick.bCanEverTick = false;

}

void APooCharacter::Move(const FInputActionValue& Value)
{
	//컨트롤러 유효 체크
	if (!Controller)return;

	//입력값 FVector2D로 변환
	FVector2D InputVector = Value.Get<FVector2D>();

	//x축 이동 0 유효성 체크
	if (!FMath::IsNearlyZero(InputVector.X))
	{
		//컨트롤러 Yaw 회전값으로 방향 벡터 계산
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		//캐릭터 이동
		AddMovementInput(Direction, InputVector.X);
	}

	//y축 이동 0 유효성 체크
	if (!FMath::IsNearlyZero(InputVector.Y))
	{
		//컨트롤러 Yaw 회전값으로 방향 벡터 계산
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		//캐릭터 이동
		AddMovementInput(Direction, InputVector.Y);
	}

}


// Called when the game starts or when spawned
void APooCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APooCharacter::Look(const FInputActionValue& Value)
{
	//컨트롤러 유효 체크
	if (!Controller)return;

	//입력값 FVector2D로 변환
	FVector2D InputVector = Value.Get<FVector2D>();

	//컨트롤러 Yaw 회전
	AddControllerYawInput(InputVector.X);
	//컨트롤러 Pitch 회전
	AddControllerPitchInput(InputVector.Y);
}

void APooCharacter::JumpStart(const FInputActionValue& Value)
{
	//입력 유효성 체크
	if(Value.Get<bool>())
	{
		Jump();
	}
}

void APooCharacter::JumpEnd(const FInputActionValue& Value)
{
	//입력 유효성 체크
	if (!Value.Get<bool>())
	{
		StopJumping();
	}

}

void APooCharacter::SprintStart(const FInputActionValue& Value)
{
	//입력 유효성 체크
	if (Value.Get<bool>())
	{
		//달리기 속도 계산
		SprintSpeed = WalkSpeed * SprintMultiplier;
		//캐릭터 이동 속도 적용
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}

void APooCharacter::SprintEnd(const FInputActionValue& Value)
{
	//입력 유효성 체크
	if (!Value.Get<bool>())
	{
		//캐릭터 이동 속도 적용
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

// Called every frame
void APooCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APooCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//언리얼 엔진 인풋 컴퍼넌트 Cast
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//플레이어 컨트롤러 Cast
		if (APooPlayerController* PlayerController = Cast<APooPlayerController>(GetController()))
		{
			//컨트롤러 Move 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->MoveAction,
				ETriggerEvent::Triggered, 
				this,
				&APooCharacter::Move);

			//컨트롤러 Look 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->LookAction,
				ETriggerEvent::Triggered,
				this,
				&APooCharacter::Look);

			//컨트롤러 Jump 시작 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->JumpAction,
				ETriggerEvent::Triggered,
				this,
				&APooCharacter::JumpStart);

			//컨트롤러 Jump 끝 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->JumpAction,
				ETriggerEvent::Completed,
				this,
				&APooCharacter::JumpEnd);

			//컨트롤러 Sprint 시작 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->SprintAction,
				ETriggerEvent::Triggered,
				this,
				&APooCharacter::SprintStart);

			//컨트롤러 Sprint 끝 액션 바인딩
			EnhancedInputComponent->BindAction(
				PlayerController->SprintAction,
				ETriggerEvent::Completed,
				this,
				&APooCharacter::SprintEnd);

		}
	}

}

