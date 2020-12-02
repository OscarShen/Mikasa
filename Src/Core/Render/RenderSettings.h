#pragma once

#include "CoreMinimal.h"

#include "Display/Display.h"

class FRenderSettings
{
public:
    FDisplaySize DisplaySize = FDisplaySize::WIN_1600_900;

public:
    static FRenderSettings& Get();

    void SaveSettings(const std::string& Path);
    void LoadSettings(const std::string& Path);

private:
    FRenderSettings();
};