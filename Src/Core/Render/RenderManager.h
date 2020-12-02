#pragma once

#include "CoreMinimal.h"

enum class ERenderType
{
    OpenGL
};



class CORE_API FRenderManager
{
public:
    static FRenderManager& Get();

    void InitRenderStatus();

    FDisplayPtr GetDisplay();

    void RegisterDisplay(const std::string& InstanceName, const std::function<FDisplayPtr()>& DisplayCreateFunc);
    void UnRegisterDisplay(const std::string& InstanceName);

private:
    FRenderManager();

    void InitLibrary();
    void InitDisplay();

private:
    std::map<std::string, std::function<FDisplayPtr()>> RegisteredDisplay;

    FDisplayPtr Display;
    ERenderType RenderType;
};