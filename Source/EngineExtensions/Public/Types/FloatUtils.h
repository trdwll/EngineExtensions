// Copyright 2021-2022 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "FloatUtils.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UFloatUtils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToFloat (float)", CompactNodeTitle = "->", Keywords = "cast convert int32", BlueprintAutocast))
	static int32 ToInt32(const float Value) { return (int32)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToInt64 (float)", CompactNodeTitle = "->", Keywords = "cast convert int64", BlueprintAutocast))
	static int64 ToInt64(const float Value) { return (int64)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToUint8 (float)", CompactNodeTitle = "->", Keywords = "cast convert uint8", BlueprintAutocast))
	static uint8 ToUint8(const float Value) { return (uint8)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToBool (float)", CompactNodeTitle = "->", Keywords = "cast convert bool", BlueprintAutocast))
	static bool ToBool(const float Value) { return (bool)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToString (float)", CompactNodeTitle = "->", Keywords = "cast convert fstring", BlueprintAutocast))
	static FString ToString(const float Value) { return *FString::Printf(TEXT("%f"), Value); }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Float", meta = (DisplayName = "ToName (float)", CompactNodeTitle = "->", Keywords = "cast convert fname", BlueprintAutocast))
	static FName ToName(const float Value) { return FName(*FString::Printf(TEXT("%f"), Value)); }

protected:
private:
};
