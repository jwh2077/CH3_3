// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"

ACoinItem::ACoinItem()
{
	//변수 초기화
	ScoreAmount = 0;
	ItemType = FName(TEXT("Coin"));
}

void ACoinItem::ActivateItem(AActor* OtherActor)
{
	Super::ActivateItem(OtherActor);

	// 점수 획득 로직 추가
	
}
