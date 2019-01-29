// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseConfiguratorObject.h"

ABaseConfiguratorObject::ABaseConfiguratorObject()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseConfiguratorObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseConfiguratorObject::ToggleVisibility()
{
	SetVisibility(!IsVisible());
}

FVector ABaseConfiguratorObject::GetFocusLocation_Implementation() const
{
	return GetActorLocation();
}

