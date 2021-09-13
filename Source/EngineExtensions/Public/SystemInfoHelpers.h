// Copyright 2021 Russ 'trdwll' Treadwell <trdwll.com> - MIT Licensed

#pragma once

#include <CoreMinimal.h>
#include <UObject/NoExportTypes.h>

#include "SystemInfoHelpers.generated.h"

/**
 *
 */
UCLASS()
class ENGINEEXTENSIONS_API USystemInfoHelpers : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Gets the CPU Brand Name information.
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetCPUBrandName()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMisc::GetCPUBrand();
#elif PLATFORM_LINUX
		return FLinuxPlatformMisc::GetCPUBrand();
#elif PLATFORM_MAC
		return FMacPlatformMisc::GetCPUBrand();
#else
		return FString();
#endif
	}

	/**
	 * Gets the CPU Vendor Name information.
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetCPUVendorName()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMisc::GetCPUVendor();
#elif PLATFORM_LINUX
		return FLinuxPlatformMisc::GetCPUVendor();
#elif PLATFORM_MAC
		return FMacPlatformMisc::GetCPUVendor();
#else
		return FString();
#endif
	}

	/**
	 * Gets the GPU Brand Name information.
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetGPUBrandName()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMisc::GetPrimaryGPUBrand();
#elif PLATFORM_LINUX
		return FLinuxPlatformMisc::GetPrimaryGPUBrand();
#elif PLATFORM_MAC
		return FMacPlatformMisc::GetPrimaryGPUBrand();
#else
		return FString();
#endif
	}

	/**
	 * Gets the GPU Driver information.
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetGPUDriverInfo()
	{
		return GRHIAdapterUserDriverVersion;
	}

	/**
	 * Gets the number of Cores in the Platforms CPU
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static int32 GetCPUCores()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMisc::NumberOfCores();
#elif PLATFORM_LINUX
		return FLinuxPlatformMisc::NumberOfCores();
#elif PLATFORM_MAC
		return FMacPlatformMisc::NumberOfCores();
#else
		return -1;
#endif
	}

	/**
	 * Get the OS version
 	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetOSVersion()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMisc::GetOSVersion();
#elif PLATFORM_LINUX
		return FLinuxPlatformMisc::GetOSVersion();
#elif PLATFORM_MAC
		return FMacPlatformMisc::GetOSVersion();
#else
		return FString();
#endif
	}

	/**
	 * Gets the number of RAM on the system
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static int32 GetTotalRAM()
	{
		const FPlatformMemoryConstants& MemoryConstants = FPlatformMemory::GetConstants();
		return MemoryConstants.TotalPhysicalGB;
	}

	/**
	 * Get the Memory Stats
	 */
	static FPlatformMemoryStats GetMemoryStats()
	{
#if PLATFORM_WINDOWS
		return FWindowsPlatformMemory::GetStats();
#elif PLATFORM_MAC
		return FMacPlatformMemory::GetStats();
#else
		return {};
#endif
	}

	/**
	 * Get the OS name
	 */
	UFUNCTION(BlueprintCallable, Category = "EngineExtensions|USystemInfoHelpers")
	static FString GetOperatingSystem()
	{
#if PLATFORM_WINDOWS
		return "Windows";
#elif PLATFORM_LINUX
		return "Linux";
#elif PLATFORM_MAC
		return "Mac";
#else
		return FString();
#endif
	}
};
