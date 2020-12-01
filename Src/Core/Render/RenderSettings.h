#pragma once

#include "CoreMinimal.h"

#include "Display/Display.h"

class MRenderSettings
{
public:
    MDisplaySize DisplaySize = MDisplaySize::WIN_1600_900;

public:
    static MRenderSettings& Get();

    void SaveSettings(const MString& Path);
    void LoadSettings(const MString& Path);

private:
    MRenderSettings();
};