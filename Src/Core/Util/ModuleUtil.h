#pragma once

#include "CoreMinimal.h"

struct FModuleUtil
{
    static std::string GetDllName(const std::string& DllPrefix);

    static bool LoadDynamicLibrary(const std::string& DllPrefix);
};