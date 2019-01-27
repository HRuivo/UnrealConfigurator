// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseConfiguratorObject.h"
#include "PresetManagerComponent.generated.h"

USTRUCT(BlueprintType)
struct FPresetObjectData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ABaseConfiguratorObject> objectClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 slotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isVisible;
};

USTRUCT(BlueprintType)
struct FPresetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 stepCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 slotCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPresetObjectData> objects;
};

USTRUCT(BlueprintType)
struct FPresetContainer
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FPresetData> presets;
};

class UMaterial;
class UMaterialInterface;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BURROWSCONFIGURATOR_API UPresetManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPresetManagerComponent();

	UFUNCTION(BlueprintCallable)
	void LoadPresetsFile(FString Filename);
	UFUNCTION(BlueprintCallable)
	void SavePresetsToFile(FString Filename);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FPresetData GetPreset(int32 PresetIndex);

	UFUNCTION(BlueprintCallable)
	void AddPreset(FPresetData NewPreset);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DefaultPresetFilename;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPresetContainer PresetList;

};
