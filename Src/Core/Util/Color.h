#pragma once

#include "CoreMinimal.h"

class FHsvColor
{
public:
    FHsvColor(float Hue, float Saturation, float Value);

public:
    float Hue, Saturation, Value;
};

class FColor
{
public:
    FColor(const glm::vec3& InColor);
    FColor(float R, float G, float B);
    FColor(float R, float G, float B, float A);
    FColor(float R, float G, float B, bool Normalize);

    glm::vec3 getVector() const;
    glm::vec4 GetVector4() const;

    FColor operator*(float N) const;
    FColor operator*(const FColor& Color) const;

    std::string ToString() const;

public:
    float R, G, B, A;
};
