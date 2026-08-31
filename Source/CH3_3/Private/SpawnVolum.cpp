// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolum.h"

// Sets default values
ASpawnVolum::ASpawnVolum()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnVolum::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

