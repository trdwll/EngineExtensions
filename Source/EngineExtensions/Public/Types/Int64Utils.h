// Copyright 2021-2022 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "Int64Utils.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UInt64Utils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToFloat (Int64)", CompactNodeTitle = "->", Keywords = "cast convert float", BlueprintAutocast))
	static float ToFloat(const int64 Value) { return (float)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToInt32 (Int64)", CompactNodeTitle = "->", Keywords = "cast convert int32", BlueprintAutocast))
	static int32 ToInt32(const int64 Value) { return (int32)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToUint8 (Int64)", CompactNodeTitle = "->", Keywords = "cast convert uint8", BlueprintAutocast))
	static uint8 ToUint8(const int64 Value) { return (uint8)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToBool (Int64)", CompactNodeTitle = "->", Keywords = "cast convert bool", BlueprintAutocast))
	static bool ToBool(const int64 Value) { return (bool)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToString (Int64)", CompactNodeTitle = "->", Keywords = "cast convert fstring", BlueprintAutocast))
	static FString ToString(const int64 Value) { return *FString::Printf(TEXT("%lld"), Value); }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Int64", meta = (DisplayName = "ToName (Int64)", CompactNodeTitle = "->", Keywords = "cast convert fname", BlueprintAutocast))
	static FName ToName(const int64 Value) { return FName(*FString::Printf(TEXT("%lld"), Value)); }

protected:
private:
};
