#include "Color.h"

MColor::MColor(float Red, float Green, float Blue)
    : R(R)
    , G(G)
    , B(B)
    , A(1.0f)
{
}

MColor::MColor(float R, float G, float B, float A)
    : R(R)
    , G(G)
    , B(B)
    , A(A)
{
}

MColor::MColor(float R, float G, float B, bool Normalize)
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

MVector MColor::getVector() const
{
    return MVector(R, G, B);
}

MVector4 MColor::GetVector4() const
{
    return MVector4(R, G, B, A);
}

MColor MColor::operator*(float N) const
{
    return MColor(R * N, G * N, B * N, A);
}

MColor MColor::operator*(const MColor& Color) const
{
    return MColor(R * Color.R, G * Color.G, B * Color.B, A);
}

MString MColor::ToString() const
{
    return "(" + std::to_string(R) + ", " + std::to_string(G) + ", " + std::to_string(B) + ")";
}

MColor::MColor(const MVector& InColor)
    : R(InColor.r)
    , G(InColor.g)
    , B(InColor.b)
    , A(1.0f)
{

}

MHsvColor::MHsvColor(float Hue, float Saturation, float Value)
    : Hue(Hue)
    , Saturation(Saturation)
    , Value(Value)
{
}
