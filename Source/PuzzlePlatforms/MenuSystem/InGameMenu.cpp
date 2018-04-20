// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"
#include "Components/Button.h"

void UInGameMenu::OpenMainMenu()
{
	if (MenuInterface != nullptr)
	{
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}

void UInGameMenu::Cancel()
{
	Teardown();
}

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	// TODO: setup
	if (!ensure( CancelButton!= nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::Cancel);

	if (!ensure(MainMenuButton!= nullptr)) return false;
	MainMenuButton->OnClicked.AddDynamic(this, &UInGameMenu::OpenMainMenu);

	return true;
}