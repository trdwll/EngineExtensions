// Copyright 2021 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "ArrayHelpers.generated.h"

namespace ArrayHelpers
{
	// Shuffle methods from https://gist.github.com/KaosSpectrum/520b1521c898801c21f7ba3f90d70fcc <3

	template <class T>
	void ShuffleArray(T& InArray)
	{
		const int32 LastIndex = InArray.Num() - 1;
		for (int32 i = 0; i < LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(0, LastIndex);
			if (i != Index)
			{
				InArray.Swap(i, Index);
			}
		}
	}

	template <class T>
	void ShuffleArray(T& InArray, const FRandomStream& InRandomStream)
	{
		const int32 LastIndex = InArray.Num() - 1;
		for (int32 i = 0; i < LastIndex; ++i)
		{
			int32 Index = InRandomStream.RandRange(0, LastIndex);
			if (i != Index)
			{
				InArray.Swap(i, Index);
			}
		}
	}

	template <class T>
	void ShuffleArray(T& InArray, int32 Seed)
	{
		const FRandomStream Stream{ Seed };
		const int32 LastIndex = InArray.Num() - 1;
		for (int32 i = 0; i < LastIndex; ++i)
		{
			int32 Index = Stream.RandRange(0, LastIndex);
			if (i != Index)
			{
				InArray.Swap(i, Index);
			}
		}
	}

	template<class T>
	void RemoveNullEntries(T& InArray)
	{
		for (int32 i = InArray.Num() - 1; i >= 0; i--)
		{
			if (!InArray[i])
			{
				InArray.RemoveAtSwap(i);
			}
		}
	}
}

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API UArrayHelpers : public UObject
{
	GENERATED_BODY()
public:


protected:
private:
};
