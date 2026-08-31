// Fill out your copyright notice in the Description page of Project Settings.


#include "PooCharacter.h"

// Sets default values
APooCharacter::APooCharacter()
{
	//스프링 암 컴포넌트 생성
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	//카메라 컴포넌트 생성
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	//카메라 컴포넌트를 스프링 암 컴포넌트 끝에 부착
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);


	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APooCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

}

