// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
//#include "Components/StaticMeshComponent.h"
//#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AItemBase::AItemBase()
{
	// ¾À ÄÄÆ÷³ÍÆ® »ý¼º
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// ¾À ÄÄÆ÷³ÍÆ®¸¦ ·çÆ® ÄÄÆ÷³ÍÆ®·Î ¼³Á¤
	SceneComponent->SetupAttachment(RootComponent);
	// ½ºÅÂÆ½ ¸Þ½Ã ÄÄÆ÷³ÍÆ® »ý¼º
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	// ½ºÅÂÆ½ ¸Þ½Ã ÄÄÆ÷³ÍÆ®¸¦ ¾À ÄÄÆ÷³ÍÆ®¿¡ ºÎÂø
	StaticMeshComponent->SetupAttachment(SceneComponent);
	// ±¸Çü ÄÝ¸®Àü ÄÄÆ÷³ÍÆ® »ý¼º
	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollisionComponent"));
	// ±¸Çü ÄÝ¸®Àü ÄÄÆ÷³ÍÆ®¸¦ ¾À ÄÄÆ÷³ÍÆ®¿¡ ºÎÂø
	SphereCollisionComponent->SetupAttachment(SceneComponent);


	PrimaryActorTick.bCanEverTick = false;

}

void AItemBase::OnItemOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
}

void AItemBase::OnItemEndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

