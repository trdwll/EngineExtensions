// Copyright 2021 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "BoolUtils.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UBoolUtils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToFloat (bool)", CompactNodeTitle = "->", Keywords = "cast convert float", BlueprintAutocast))
	static float ToFloat(const bool Value) { return (float)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToInt64 (bool)", CompactNodeTitle = "->", Keywords = "cast convert int64", BlueprintAutocast))
	static int64 ToInt64(const bool Value) { return (int64)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToInt32 (bool)", CompactNodeTitle = "->", Keywords = "cast convert int32", BlueprintAutocast))
	static int32 ToInt32(const bool Value) { return (int32)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToUint8 (bool)", CompactNodeTitle = "->", Keywords = "cast convert uint8", BlueprintAutocast))
	static uint8 ToUint8(const bool Value) { return (uint8)Value; }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToString (bool)", CompactNodeTitle = "->", Keywords = "cast convert fstring", BlueprintAutocast))
	static FString ToString(const bool Value) { return *FString::Printf(TEXT("%d"), Value); }

	UFUNCTION(BlueprintPure, Category = "EngineExtensions|Bool", meta = (DisplayName = "ToName (bool)", CompactNodeTitle = "->", Keywords = "cast convert fname", BlueprintAutocast))
	static FName ToName(const bool Value) { return FName(*FString::Printf(TEXT("%d"), Value)); }

protected:
private:
};
