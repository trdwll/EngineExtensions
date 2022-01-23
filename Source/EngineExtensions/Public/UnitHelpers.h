// Copyright 2021-2022 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>
#include <Math/UnitConversion.h>

#include "UnitHelpers.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UUnitHelpers : public UObject
{
	GENERATED_BODY()

public:

	/** Check whether it is possible to convert a number between the two specified units */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static bool AreUnitsCompatible(const EUnit From, const EUnit To) { return FUnitConversion::AreUnitsCompatible(From, To); }

	/** Get the display string for the the specified unit type */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static FString GetUnitDisplayString(const EUnit Unit) { return FUnitConversion::GetUnitDisplayString(Unit); }

	/** Helper function to find a unit from a string (name or display string) */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static EUnit UnitFromString(const FString& UnitString) { return FUnitConversion::UnitFromString(*UnitString).GetValue(); }

	//****
	// Unit Conversion
	//****

	/** Convert the specified number from one unit to another. Does nothing if the units are incompatible. */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static uint8 Convert8(const uint8 Value, const EUnit From, const EUnit To) { return FUnitConversion::Convert<uint8>(Value, From, To); }

	/** Convert the specified number from one unit to another. Does nothing if the units are incompatible. */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static int32 Convert32(const int32 Value, const EUnit From, const EUnit To) { return FUnitConversion::Convert<int32>(Value, From, To); }

	/** Convert the specified number from one unit to another. Does nothing if the units are incompatible. */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static int64 Convert64(const int64 Value, const EUnit From, const EUnit To) { return FUnitConversion::Convert<int64>(Value, From, To); }

	/** Convert the specified number from one unit to another. Does nothing if the units are incompatible. */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static float ConvertFloat(const float Value, const EUnit From, const EUnit To) { return FUnitConversion::Convert<float>(Value, From, To); }

	/** Quantizes this number to the most appropriate unit for user friendly presentation (e.g. 1000m returns 1km). */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static void QuantizeUnitsToBestFit8(const uint8 Value, const EUnit Unit, uint8& NewValue, EUnit& NewUnit) { QuantizeUnitsToBestFitImpl(Value, Unit, NewValue, NewUnit); }

	/** Quantizes this number to the most appropriate unit for user friendly presentation (e.g. 1000m returns 1km). */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static void QuantizeUnitsToBestFit32(const int32 Value, const EUnit Unit, int32& NewValue, EUnit& NewUnit) { QuantizeUnitsToBestFitImpl(Value, Unit, NewValue, NewUnit); }

	/** Quantizes this number to the most appropriate unit for user friendly presentation (e.g. 1000m returns 1km). */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static void QuantizeUnitsToBestFit64(const int64 Value, const EUnit Unit, int64& NewValue, EUnit& NewUnit) { QuantizeUnitsToBestFitImpl(Value, Unit, NewValue, NewUnit); }

	/** Quantizes this number to the most appropriate unit for user friendly presentation (e.g. 1000m returns 1km). */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|UnitHelpers")
	static void QuantizeUnitsToBestFitFloat(const float Value, const EUnit Unit, float& NewValue, EUnit& NewUnit) { QuantizeUnitsToBestFitImpl(Value, Unit, NewValue, NewUnit); }

protected:
private:

	template<typename T>
	static void QuantizeUnitsToBestFitImpl(const T Value, const EUnit Unit, T& NewValue, EUnit& NewUnit)
	{
		const FNumericUnit<T> Val = FUnitConversion::QuantizeUnitsToBestFit(Value, Unit);
		NewValue = Val.Value;
		NewUnit = Val.Units;
	}
};
