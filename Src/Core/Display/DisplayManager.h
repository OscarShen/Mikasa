#pragma once

#include "CoreMinimal.h"

class CORE_API MDisplayManager
{
public:
    static MDisplayManager& Get();

    void CreateDisplay();

private:
    MDisplayManager();
};