// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameinstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameinstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:	
	UPuzzlePlatformsGameinstance(const FObjectInitializer & FObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
	void Host() override;

	UFUNCTION(Exec)
	void Join(const FString& Address) override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void InGameLoadMenu();

	virtual void LoadMainMenu() override;
private:
	 TSubclassOf<class UUserWidget> MenuClass;
	 TSubclassOf<class UUserWidget> InGameMenuClass;

	 class UMainMenu* Menu;

};
