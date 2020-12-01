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

MDisplaySize::MDisplaySize(const MString& InName, Int32 InWidth, Int32 InHeight)
    : Name(InName)
    , Width(InWidth)
    , Height(InHeight)
{
}

Int32 MDisplaySize::GetWidth()
{
    return Width;
}

Int32 MDisplaySize::GetHeight()
{
    return Height;
}

const MString& MDisplaySize::GetName()
{
    return Name;
}

MDisplay::MDisplay()
{
}

MDisplay::~MDisplay()
{
}

MDisplayFactory::MDisplayFactory()
{
}

MDisplayFactory& MDisplayFactory::Get()
{
    static MDisplayFactory Factory;
    return Factory;
}

void MDisplayFactory::Register(const MString& InstanceName, MDisplayInstanceBase* Instance)
{
    CraeteInstances.emplace(InstanceName, Instance);
}

void MDisplayFactory::UnRegister(const MString& InstanceName)
{
    CraeteInstances.erase(InstanceName);
}

TSharedPtr<MDisplay> MDisplayFactory::CreateInstance(const MString& TypeName)
{
    if (CraeteInstances.find(TypeName) != CraeteInstances.end())
    {
        return CraeteInstances[TypeName]->CreateInstance();
    }
    return nullptr;
}

MDisplayInstanceBase::MDisplayInstanceBase(const MString& InstanceName)
    : Name(InstanceName)
{
    MDisplayFactory::Get().Register(InstanceName, this);
}

MDisplayInstanceBase::~MDisplayInstanceBase()
{
    MDisplayFactory::Get().UnRegister(Name);
}
