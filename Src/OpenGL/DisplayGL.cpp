#include "CoreMinimal.h"

#include "Render/RenderManager.h"
#include "Render/Display/Display.h"

class FDisplayGL : public FDisplay
{
public:
    virtual void InitDisplay() override
    {

    }
    virtual void RefreshDisplay() override
    {
    }

    virtual void SetDisplaySize(const FDisplaySize& InDisplaySize) override
    {

    }
    virtual void SetVSync(bool Enable) override
    {

    }
    virtual void SetInitBackground(const FColor& Color) override
    {

    }
    virtual void SetTitle(const std::string& Title) override
    {

    }
};

class FDisplayRegisterGL
{
public:
    FDisplayRegisterGL()
    {
        FRenderManager::Get().RegisterDisplay("OpenGL", []() -> FDisplayPtr
            {
                return std::make_shared<FDisplayGL>();
            });
    }

    ~FDisplayRegisterGL()
    {
        FRenderManager::Get().UnRegisterDisplay("OpenGL");
    }
};

namespace
{
    FDisplayRegisterGL DisplayGL;
}
