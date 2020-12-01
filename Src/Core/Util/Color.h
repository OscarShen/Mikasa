#pragma once

#include "CoreMinimal.h"

class MHsvColor
{
public:
    MHsvColor(float Hue, float Saturation, float Value);

public:
    float Hue, Saturation, Value;
};

class MColor
{
public:
    MColor(const MVector& InColor);
    MColor(float R, float G, float B);
    MColor(float R, float G, float B, float A);
    MColor(float R, float G, float B, bool Normalize);

    MVector getVector() const;
    MVector4 GetVector4() const;

    MColor operator*(float N) const;
    MColor operator*(const MColor& Color) const;

    MString ToString() const;

public:
    float R, G, B, A;
};
