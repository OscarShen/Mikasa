#include "Display.h"

FDisplaySize FDisplaySize::FULL_SCREEN = FDisplaySize("Full Screen", 0, 0);
FDisplaySize FDisplaySize::WIN_1600_900 = FDisplaySize("1600 x 900", 1600, 900);

FDisplaySize FDisplaySize::GetDisplaySizeByName(const std::string& Name)
{
#define RETURN_DISPLAY_SIZE_IF_EQUAL(Name, DisplaySize)\
    if (Name == DisplaySize.GetName()) { return DisplaySize; }

    RETURN_DISPLAY_SIZE_IF_EQUAL(Name, FDisplaySize::FULL_SCREEN);
    RETURN_DISPLAY_SIZE_IF_EQUAL(Name, FDisplaySize::WIN_1600_900);

#undef RETURN_DISPLAY_SIZE_IF_EQUAL

    return FDisplaySize::WIN_1600_900;
}

FDisplaySize::FDisplaySize(const std::string& InName, int32_t InWidth, int32_t InHeight)
    : Name(InName)
    , Width(InWidth)
    , Height(InHeight)
{
}

int32_t FDisplaySize::GetWidth()
{
    return Width;
}

int32_t FDisplaySize::GetHeight()
{
    return Height;
}

const std::string& FDisplaySize::GetName()
{
    return Name;
}

FDisplay::FDisplay()
{
}

FDisplay::~FDisplay()
{
}
