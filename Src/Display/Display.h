#pragma once

#include "CoreMinimal.h"

class MDisplaySize
{
public:
    static MDisplaySize FULL_SCREEN;
    static MDisplaySize WIN_1600_900;

    static MDisplaySize GetDisplaySizeByName(const MString& Name);
    
public:
    MDisplaySize(const MString& InName, MInt32 InWidth, MInt32 InHeight);

    MInt32 GetWidth();
    MInt32 GetHeight();
    const MString& GetName();

private:
    MString Name;
    MInt32 Width;
    MInt32 Height;
};

class MDisplay
{

};