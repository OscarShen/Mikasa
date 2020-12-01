#include "DisplayGL.h"

class MDisplayGLInstance : public MDisplayInstanceBase
{
public:
    MDisplayGLInstance()
        : MDisplayInstanceBase("OpenGL")
    {
    }
    virtual TSharedPtr<MDisplay> CreateInstance() override
    {
        return std::make_shared<MDisplayGL>();
    }
};

namespace
{
    MDisplayGLInstance Test;
}

void MDisplayGL::InitDisplay()
{
}

void MDisplayGL::RefreshDisplay()
{
}

void MDisplayGL::SetDisplaySize(const MDisplaySize& InDisplaySize)
{

}

void MDisplayGL::SetVSync(bool Enable)
{
}

void MDisplayGL::SetInitBackground(const MColor& Color)
{
}

void MDisplayGL::SetTitle(const MString& Title)
{
}
