#include "../../Public/EntityActions/TransformAction.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "../../Public/Components/TransformComponent.h"

void TransformAction::Execute()
{
    EntityAction::Execute();
    auto* TransformComp = dynamic_cast<TransformComponent*>(Comp);
    if (!TransformComp)
    {
        throw std::invalid_argument("TransformAction::Execute: Transform Component cannot be null");
    }

    switch (Type)
    {
    case Position:
        MoveComp(TransformComp);
        break;
    case Rotation:
        RotateComp(TransformComp);
        break;
    case Scale:
        ScaleComp(TransformComp);
        break;
    }
}

void TransformAction::MoveComp(TransformComponent* TransformComp) const
{
    TransformComp->Position.X += DeltaX;
    TransformComp->Position.Y += DeltaY;
    TransformComp->Position.Z += DeltaZ;

    std::cout << "New position of Entity " + std::to_string(TransformComp->GetEntity().GetId()) +
        ": (" + std::to_string(TransformComp->Position.X) + " " +
                std::to_string(TransformComp->Position.Y) + " " +
                std::to_string(TransformComp->Position.Z) + ")\n\n";
}

void TransformAction::RotateComp(TransformComponent* TransformComp) const
{
    TransformComp->Rotation.X += DeltaX;
    TransformComp->Rotation.Y += DeltaY;
    TransformComp->Rotation.Z += DeltaZ;

    std::cout << "New rotation of Entity " + std::to_string(TransformComp->GetEntity().GetId()) +
    ": (" + std::to_string(TransformComp->Rotation.X) + " " +
            std::to_string(TransformComp->Rotation.Y) + " " +
            std::to_string(TransformComp->Rotation.Z) + ")\n\n";
}

void TransformAction::ScaleComp(TransformComponent* TransformComp) const
{
    TransformComp->Scale.X += DeltaX;
    TransformComp->Scale.Y += DeltaY;
    TransformComp->Scale.Z += DeltaZ;

    std::cout << "New scale of Entity " + std::to_string(TransformComp->GetEntity().GetId()) +
    ": (" + std::to_string(TransformComp->Scale.X) + " " +
            std::to_string(TransformComp->Scale.Y) + " " +
            std::to_string(TransformComp->Scale.Z) + ")\n\n";
}
