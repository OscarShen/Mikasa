#include "Color.h"

FColor::FColor(float Red, float Green, float Blue)
    : R(R)
    , G(G)
    , B(B)
    , A(1.0f)
{
}

FColor::FColor(float R, float G, float B, float A)
    : R(R)
    , G(G)
    , B(B)
    , A(A)
{
}

FColor::FColor(float R, float G, float B, bool Normalize)
    : R(R)
    , G(G)
    , B(B)
    , A(1.0f)
{
    if (Normalize)
    {
        R /= 255.0f;
        G /= 255.0f;
        B /= 255.0f;
    }
}

glm::vec3 FColor::getVector() const
{
    return glm::vec3(R, G, B);
}

glm::vec4 FColor::GetVector4() const
{
    return glm::vec4(R, G, B, A);
}

FColor FColor::operator*(float N) const
{
    return FColor(R * N, G * N, B * N, A);
}

FColor FColor::operator*(const FColor& Color) const
{
    return FColor(R * Color.R, G * Color.G, B * Color.B, A);
}

std::string FColor::ToString() const
{
    return "(" + std::to_string(R) + ", " + std::to_string(G) + ", " + std::to_string(B) + ")";
}

FColor::FColor(const glm::vec3& InColor)
    : R(InColor.r)
    , G(InColor.g)
    , B(InColor.b)
    , A(1.0f)
{

}

FHsvColor::FHsvColor(float Hue, float Saturation, float Value)
    : Hue(Hue)
    , Saturation(Saturation)
    , Value(Value)
{
}

FColor FColor::BlackColor = FColor(0, 0, 0, 1.0f);
