#include "RenderManager.h"

FRenderManager& FRenderManager::Get()
{
    static FRenderManager RenderManager;
    return RenderManager;
}

void FRenderManager::RegisterDisplay(const std::string& InstanceName, const std::function<FDisplayPtr()>& DisplayCreateFunc)
{
    RegisteredDisplay.emplace(InstanceName, DisplayCreateFunc);
}

void FRenderManager::UnRegisterDisplay(const std::string& InstanceName)
{
    RegisteredDisplay.erase(InstanceName);
}
