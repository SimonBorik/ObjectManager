#pragma once

#include "../TransformType.h"
#include "../../Public/EntityAction.h"

class TransformAction : EntityAction
{
public:
    explicit TransformAction(ObjectManager* Manager) : EntityAction(Manager){}

    TransformAction(ObjectManager* Manager, bool Visible, Component* ByComponent, TransformType NewType, float X, float Y, float Z)
        : EntityAction(Manager, Visible, ByComponent), Type(NewType), DeltaX(X), DeltaY(Y), DeltaZ(Z){}

    void Execute() override;

    void MoveComp(TransformComponent* TransformComp) const;

    void RotateComp(TransformComponent* TransformComp) const;

    void ScaleComp(TransformComponent* TransformComp) const;

private:
    TransformType Type = Position;
    
    float DeltaX = 0;
    
    float DeltaY = 0;
    
    float DeltaZ = 0;
};
