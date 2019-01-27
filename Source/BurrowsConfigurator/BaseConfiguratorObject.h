// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseConfiguratorObject.generated.h"

UCLASS()
class BURROWSCONFIGURATOR_API ABaseConfiguratorObject : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseConfiguratorObject();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Configurator")
	void SetVisibility(bool IsVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Configurator")
	bool IsVisible() const;

	UFUNCTION(BlueprintCallable, Category = "Configurator")
	void ToggleVisibility();


	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Configurator")
	void ResetMaterial();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Configurator")
	void SetMaterial(UMaterialInterface* NewMaterial);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Configurator")
	UMaterialInterface* GetAssignedMaterial() const;


protected:
	virtual void BeginPlay() override;

};
