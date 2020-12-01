#pragma once

#include "CoreMinimal.h"
#include "Util/Color.h"

class CORE_API MDisplaySize
{
public:
    static MDisplaySize FULL_SCREEN;
    static MDisplaySize WIN_1600_900;

    static MDisplaySize GetDisplaySizeByName(const MString& Name);
    
public:
    MDisplaySize(const MString& InName, Int32 InWidth, Int32 InHeight);

    Int32 GetWidth();
    Int32 GetHeight();
    const MString& GetName();

private:
    MString Name;
    Int32 Width;
    Int32 Height;
};

class CORE_API MDisplay
{
public:
    MDisplay();
    virtual ~MDisplay();

    virtual void InitDisplay() = 0;
    virtual void RefreshDisplay() = 0;

    virtual void SetDisplaySize(const MDisplaySize& InDisplaySize) = 0;
    virtual void SetVSync(bool Enable) = 0;
    virtual void SetInitBackground(const MColor& Color) = 0;
    virtual void SetTitle(const MString& Title) = 0;
};

class CORE_API MDisplayInstanceBase
{
public:
    MDisplayInstanceBase(const MString& InstanceName);
    virtual ~MDisplayInstanceBase();
    virtual TSharedPtr<MDisplay> CreateInstance() = 0;

private:
    MString Name;
};

class CORE_API MDisplayFactory
{
public:
    MDisplayFactory();

    static MDisplayFactory& Get();

    void Register(const MString& InstanceName, MDisplayInstanceBase* Instance);
    void UnRegister(const MString& InstanceName);

    TSharedPtr<MDisplay> CreateInstance(const MString& TypeName);

private:
    TMap<MString, MDisplayInstanceBase*> CraeteInstances;
};
