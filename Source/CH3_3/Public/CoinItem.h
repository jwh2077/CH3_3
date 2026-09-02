// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "CoinItem.generated.h"

/**
 * 
 */
UCLASS()
class CH3_3_API ACoinItem : public AItemBase
{
	GENERATED_BODY()
	

public:
	ACoinItem();

	//추가할 점수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Coin")
	int32 ScoreAmount;

	//아이템 작동 함수
	virtual void ActivateItem(AActor* OtherActor) override;

};
