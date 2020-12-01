#pragma once

#include "CoreMinimal.h"
#include "Display/Display.h"

class MDisplayGL : public MDisplay
{
public:
    virtual void InitDisplay() override;
    virtual void RefreshDisplay() override;

    virtual void SetDisplaySize(const MDisplaySize& InDisplaySize) override;
    virtual void SetVSync(bool Enable) override;
    virtual void SetInitBackground(const MColor& Color) override;
    virtual void SetTitle(const MString& Title) override;
};