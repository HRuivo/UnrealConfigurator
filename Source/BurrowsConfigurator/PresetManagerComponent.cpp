// Fill out your copyright notice in the Description page of Project Settings.

#include "PresetManagerComponent.h"
#include "FileHelper.h"
#include "Paths.h"
#include "Json.h"
#include "JsonObjectConverter.h"

UPresetManagerComponent::UPresetManagerComponent()
{
}


void UPresetManagerComponent::LoadPresetsFile(FString Filename)
{
	FString FullFilename = FString::Printf(TEXT("%s/%s.json"), *FPaths::ProjectContentDir(), *Filename);
	FString JsonString;

	if (FFileHelper::LoadFileToString(JsonString, *FullFilename))
	{
		bool success = FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &PresetList, 0, 0);
	}
}

void UPresetManagerComponent::SavePresetsToFile(FString Filename)
{
	FString JsonString;

	FString FullFilename = FString::Printf(TEXT("%s/%s.json"), *FPaths::ProjectContentDir(), *Filename);

	if (FJsonObjectConverter::UStructToJsonObjectString(PresetList, JsonString))
	{
		FFileHelper::SaveStringToFile(JsonString, *FullFilename);
	}
}

FPresetData UPresetManagerComponent::GetPreset(int32 PresetIndex)
{
	if (PresetList.presets.Num() > 0)
	{
		return PresetList.presets[PresetIndex];
	}

	return FPresetData();
}

void UPresetManagerComponent::AddPreset(FPresetData NewPreset)
{
	PresetList.presets.Add(NewPreset);
}
