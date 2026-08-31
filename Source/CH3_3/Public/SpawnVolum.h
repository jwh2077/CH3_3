// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolum.generated.h"

class UBoxComponent;

UCLASS()
class CH3_3_API ASpawnVolum : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolum();

	//씬 컴퍼넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawing")
	USceneComponent* SceneComp;
	//스폰범위 박스
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawing")
	UBoxComponent* SpawningBox;
	//아이템 스폰할 아이템이 들어있는 데이터 테이블
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawing")
	UDataTable* ItemDataTable;
	//아이템 랜덤 생성
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomItem();
	//랜던 아이템 class 반환
	FItemSpawnRow* GetRandomItem()const;
	//아이템 스폰
	AActor* SpawnItem(TSubclassOf<AActor>ItemClass);
	//박스안 랜덤 범위 반환
	FVector GetRandomPointInVolume() const;

};
