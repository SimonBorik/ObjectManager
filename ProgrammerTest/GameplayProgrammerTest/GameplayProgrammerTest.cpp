// ReSharper disable All
#include <iostream>
#include <string>

#include "public/EntityActions/TransformAction.h"
#include "Public/Components/TransformComponent.h"

int main(int argc, char* argv[])
{
    std::vector<std::shared_ptr<Entity>> Entities;
    
    std::shared_ptr<Entity> EntityA = std::make_shared<Entity>(0);
    std::shared_ptr<Entity> EntityB = std::make_shared<Entity>(1);
    
    Entities.emplace_back(EntityA);
    Entities.emplace_back(EntityB);
    
    auto TransformA = EntityA->CreateComponent<TransformComponent>();
    auto TransformB = EntityB->CreateComponent<TransformComponent>();

    // Create 1 invisible and 1 visible actions for Entity A and cache them (without any reference, they get automatically destroyed)
    auto ActionA1 = EntityA->GetComponent<TransformComponent>()->CreateObject<EntityAction>(EntityA->GetObjectManager(), false);
    auto ActionA2 = EntityA->GetComponent<TransformComponent>()->CreateObject<TransformAction>(EntityA->GetObjectManager(), true, TransformA.get(), Position, 1.0f, 1.0f, 1.0f);

    // Create 1 generic Object and 3 different Transform actions for Entity B ( all visible)
    auto ActionB1 = EntityB->GetComponent<TransformComponent>()->CreateObject<Object>(EntityB->GetObjectManager());
    auto ActionB2 = EntityB->GetComponent<TransformComponent>()->CreateObject<TransformAction>(EntityB->GetObjectManager(), true, TransformB.get(), Position, 1.0f, 1.0f, 1.0f);
    auto ActionB3 = EntityB->GetComponent<TransformComponent>()->CreateObject<TransformAction>(EntityB->GetObjectManager(), true, TransformB.get(), Rotation, 7.3f, 90.2f, 100.3f);
    auto ActionB4 = EntityB->GetComponent<TransformComponent>()->CreateObject<TransformAction>(EntityB->GetObjectManager(), true, TransformB.get(), Scale, 7.3f, 90.2f, 100.3f);
    
    // For each entity
    for (auto& Entity : Entities)
    {
        std::cout << "Number of objects owned by Object Manager of Entity " + std::to_string(Entity->GetId()) + ": " + std::to_string(Entity->GetObjectManager()->GetObjects().size()) + "\n\n";
        
        // Execute visible actions
        for (auto* Action : Entity->GetObjectManager()->GetVisibleActions())
        {
            Action->Execute();
        }
    }
    
    return 0;
}
