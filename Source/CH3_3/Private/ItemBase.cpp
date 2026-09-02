// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AItemBase::AItemBase()
{
	// 씬 컴포넌트 생성
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// 씬 컴포넌트를 루트 컴포넌트로 설정
	SetRootComponent(SceneComponent);
	// 스태틱 메시 컴포넌트 생성
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	// 스태틱 메시 컴포넌트를 씬 컴포넌트에 부착
	StaticMeshComponent->SetupAttachment(SceneComponent);
	// 구형 콜리전 컴포넌트 생성
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	// 구형 콜리전 컴포넌트를 씬 컴포넌트에 부착
	CollisionComponent->SetupAttachment(SceneComponent);

	//함수 바인딩
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnItemOverlap);
	//함수 바인딩
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnItemEndOverlap);



	PrimaryActorTick.bCanEverTick = false;

}

void AItemBase::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
}

void AItemBase::OnItemEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}

void AItemBase::ActivateItem(AActor* OtherActor)
{
	//변수로 저장
	UParticleSystemComponent* Particle = nullptr;

	// 아이템 획득 효과 재생
	if (PickupEffect)
	{
		Particle = UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			PickupEffect,
			GetActorLocation(),
			GetActorRotation(),
			true
		);
	}
	// 아이템 획득 사운드 재생
	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			PickupSound,
			GetActorLocation());
	}

	if (Particle)
	{
		// 파티클 시스템이 끝난 후 파티클을 제거하기 위해 타이머 설정
		FTimerHandle DistroyTimerHandle;

		// 람다 함수를 사용하여 타이머가 만료되면 파티클 컴포넌트를 제거
		GetWorld()->GetTimerManager().SetTimer(
			DistroyTimerHandle,
			[Particle]
			{
				Particle->DestroyComponent();
			},
			2.0f,
			false
		);
	}
}

void AItemBase::DestroyItem()
{
	//아이템 삭제
	Destroy();
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

FName AItemBase::GetItemType() const
{
	return ItemType;
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

