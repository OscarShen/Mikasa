#include "CoreMinimal.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Render/RenderManager.h"
#include "Render/Display/Display.h"

#include "Base/Color.h"

class FDisplayGL : public FDisplay
{
public:
    FDisplayGL()
        : FDisplay()
        , Window(nullptr)
        , DisplaySize(FDisplaySize::WIN_1600_900)
        , BGColor(FColor::BlackColor)
        , Title("Mikasa")
    {
    }

    virtual ~FDisplayGL()
    {
        DestroyDisplay();
    }

    virtual void InitDisplay() override
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        Window = glfwCreateWindow(
            DisplaySize.GetWidth(),
            DisplaySize.GetHeight(),
            Title.c_str(), NULL, NULL);

        glfwMakeContextCurrent(Window);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        bool bGladInit = !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    }

    virtual void RefreshDisplay() override
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    virtual void DestroyDisplay() override
    {
        glfwTerminate();
        Window = nullptr;
    }

    virtual void CloseDisplay() override
    {
        glfwSetWindowShouldClose(Window, 1);
    }

    virtual bool ShouldCloseDisplay() override
    {
        return glfwWindowShouldClose(Window);
    }

    virtual void SwapBuffers() override
    {
        glfwSwapBuffers(Window);
        glfwPollEvents();
    }

    virtual void SetDisplaySize(const FDisplaySize& InDisplaySize) override
    {
        DisplaySize = InDisplaySize;
    }

    virtual void SetVSync(bool Enable) override
    {
        
    }

    virtual void SetInitBackground(const FColor& Color) override
    {
        BGColor = Color;
    }

    virtual void SetTitle(const std::string& InTitle) override
    {
        Title = InTitle;
    }

private:
    GLFWwindow* Window;
    FDisplaySize DisplaySize;
    FColor BGColor;
    std::string Title;
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
