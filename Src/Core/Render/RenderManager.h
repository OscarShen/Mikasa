#pragma once

#include "CoreMinimal.h"

class CORE_API FRenderManager
{
public:
    static FRenderManager& Get();

    void RegisterDisplay(const std::string& InstanceName, const std::function<FDisplayPtr()>& DisplayCreateFunc);
    void UnRegisterDisplay(const std::string& InstanceName);

private:
    std::map<std::string, std::function<FDisplayPtr()>> RegisteredDisplay;
};