#include "Display.h"

MDisplaySize MDisplaySize::FULL_SCREEN = MDisplaySize("Full Screen", 0, 0);
MDisplaySize MDisplaySize::WIN_1600_900 = MDisplaySize("1600 x 900", 1600, 900);

MDisplaySize MDisplaySize::GetDisplaySizeByName(const MString& Name)
{
#define RETURN_DISPLAY_SIZE_IF_EQUAL(Name, DisplaySize)\
    if (Name == DisplaySize.GetName()) { return DisplaySize; }

    RETURN_DISPLAY_SIZE_IF_EQUAL(Name, MDisplaySize::FULL_SCREEN);
    RETURN_DISPLAY_SIZE_IF_EQUAL(Name, MDisplaySize::WIN_1600_900);

#undef RETURN_DISPLAY_SIZE_IF_EQUAL

    return MDisplaySize::WIN_1600_900;
}

MDisplaySize::MDisplaySize(const MString& InName, MInt32 InWidth, MInt32 InHeight)
    : Name(InName)
    , Width(InWidth)
    , Height(InHeight)
{
}

MInt32 MDisplaySize::GetWidth()
{
    return Width;
}

MInt32 MDisplaySize::GetHeight()
{
    return Height;
}

const MString& MDisplaySize::GetName()
{
    return Name;
}
