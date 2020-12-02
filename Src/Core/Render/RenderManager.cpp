#include "RenderManager.h"
#include "Util/ModuleUtil.h"
#include "Render/Display/Display.h"

FRenderManager& FRenderManager::Get()
{
    static FRenderManager RenderManager;
    return RenderManager;
}

void FRenderManager::InitRenderStatus()
{
    InitLibrary();
    InitDisplay();
}

FDisplayPtr FRenderManager::GetDisplay()
{
    if (Display == nullptr)
    {
        InitDisplay();
    }

    return Display;
}

void FRenderManager::RegisterDisplay(const std::string& InstanceName, const std::function<FDisplayPtr()>& DisplayCreateFunc)
{
    RegisteredDisplay.emplace(InstanceName, DisplayCreateFunc);
}

void FRenderManager::UnRegisterDisplay(const std::string& InstanceName)
{
    RegisteredDisplay.erase(InstanceName);
}

FRenderManager::FRenderManager()
    : RenderType(ERenderType::OpenGL)
{

}

void FRenderManager::InitLibrary()
{
    if (Display == nullptr)
    {
        switch (RenderType)
        {
        case ERenderType::OpenGL:
            FModuleUtil::LoadDynamicLibrary(GET_ENUM_NAME_CHECKED(ERenderType, OpenGL));
            break;
        default:
            FModuleUtil::LoadDynamicLibrary(GET_ENUM_NAME_CHECKED(ERenderType, OpenGL));
            break;
        }
    }
}

void FRenderManager::InitDisplay()
{
    if (Display == nullptr)
    {
        switch (RenderType)
        {
        case ERenderType::OpenGL:
        {
            Display = RegisteredDisplay[GET_ENUM_NAME_CHECKED(ERenderType, OpenGL)]();
            break;
        }
        default:
            Display = RegisteredDisplay[GET_ENUM_NAME_CHECKED(ERenderType, OpenGL)]();
            break;
        }

        Display->InitDisplay();
    }
}
