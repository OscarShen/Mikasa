#pragma once

#include "CoreMinimal.h"
#include "Util/Color.h"

class CORE_API FDisplaySize
{
public:
    static FDisplaySize FULL_SCREEN;
    static FDisplaySize WIN_1600_900;

    static FDisplaySize GetDisplaySizeByName(const std::string& Name);
    
public:
    FDisplaySize(const std::string& InName, int32_t InWidth, int32_t InHeight);

    int32_t GetWidth();
    int32_t GetHeight();
    const std::string& GetName();

private:
    std::string Name;
    int32_t Width;
    int32_t Height;
};

class CORE_API FDisplay
{
public:
    FDisplay();
    virtual ~FDisplay();

    virtual void InitDisplay() = 0;
    virtual void RefreshDisplay() = 0;

    virtual void SetDisplaySize(const FDisplaySize& InDisplaySize) = 0;
    virtual void SetVSync(bool Enable) = 0;
    virtual void SetInitBackground(const FColor& Color) = 0;
    virtual void SetTitle(const std::string& Title) = 0;
};