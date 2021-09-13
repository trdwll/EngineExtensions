// Copyright 2021 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "Int32Utils.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UInt32Utils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToFloat (Int32)", CompactNodeTitle = "->", Keywords = "cast convert float", BlueprintAutocast))
	static float ToFloat(const int32 Value) { return (float)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToInt64 (Int32)", CompactNodeTitle = "->", Keywords = "cast convert int64", BlueprintAutocast))
	static int64 ToInt32(const int32 Value) { return (int64)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToUint8 (Int32)", CompactNodeTitle = "->", Keywords = "cast convert uint8", BlueprintAutocast))
	static uint8 ToUint8(const int32 Value) { return (uint8)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToBool (Int32)", CompactNodeTitle = "->", Keywords = "cast convert bool", BlueprintAutocast))
	static bool ToBool(const int32 Value) { return (bool)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToString (Int32)", CompactNodeTitle = "->", Keywords = "cast convert fstring", BlueprintAutocast))
	static FString ToString(const int32 Value) { return *FString::Printf(TEXT("%d"), Value); }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int32", meta = (DisplayName = "ToName (Int32)", CompactNodeTitle = "->", Keywords = "cast convert fname", BlueprintAutocast))
	static FName ToName(const int32 Value) { return FName(*FString::Printf(TEXT("%d"), Value)); }

protected:
private:
};
