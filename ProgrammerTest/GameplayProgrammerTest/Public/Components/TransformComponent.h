#pragma once
#include "Component.h"

struct PositionStruct
{
    float X = 0;
    float Y = 0;
    float Z = 0;

    PositionStruct operator+(PositionStruct Other) const
    {
        return {X + Other.X, Y + Other.Y, Z + Other.Z};
    }

    PositionStruct operator-(PositionStruct Other) const
    {
        return {X - Other.X, Y - Other.Y, Z - Other.Z};
    }
};

struct RotationStruct
{
    float X = 0;
    float Y = 0;
    float Z = 0;

    RotationStruct operator+(RotationStruct Other) const
    {
        return {X + Other.X, Y + Other.Y, Z + Other.Z};
    }

    RotationStruct operator-(RotationStruct Other) const
    {
        return {X - Other.X, Y - Other.Y, Z - Other.Z};
    }
};

struct ScaleStruct
{
    float X = 0;
    float Y = 0;
    float Z = 0;

    ScaleStruct operator+(ScaleStruct Other) const
    {
        return {X + Other.X, Y + Other.Y, Z + Other.Z};
    }

    ScaleStruct operator-(ScaleStruct Other) const
    {
        return {X - Other.X, Y - Other.Y, Z - Other.Z};
    }
};

class TransformComponent : public Component
{
public:
    explicit TransformComponent(Entity* Entity) : Component(Entity){}

    PositionStruct Position;

    RotationStruct Rotation;

    ScaleStruct Scale;
};
