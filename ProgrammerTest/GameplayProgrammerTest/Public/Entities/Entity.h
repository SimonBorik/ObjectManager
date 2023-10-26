// ReSharper disable All
#pragma once
#include <memory>
#include <set>

#include "../Managers/ObjectManager.h"
#include "../Managers/EntityActionManager.h"


class Component;
class TransformComponent;

class Entity
{

public:
    explicit Entity(size_t NewId) : Id(NewId), ObjManager(std::make_unique<EntityActionManager>(this)){};
    
    virtual ~Entity() = default;

    size_t GetId() const;
    
    // Create component of any type and push it to the Components set
    template <typename ComponentType, typename... Args>
    std::shared_ptr<ComponentType> CreateComponent(Args&&... args)
    {
        std::shared_ptr<ComponentType> NewComponent = std::make_shared<ComponentType>(this, std::forward<Args>(args)...);
        Components.insert(NewComponent);
        return NewComponent;
    }

    // Find component of given type
    template <typename ComponentType>
    std::shared_ptr<ComponentType> GetComponent()
    {
        for (const auto& Comp : Components)
        {
            if (std::shared_ptr<ComponentType> SpecificComp = std::dynamic_pointer_cast<ComponentType>(Comp))
            {
                return SpecificComp;
            }
        }

        return nullptr;
    }
    
    EntityActionManager* GetObjectManager() const;
    
private:
    size_t Id;
    
    std::unique_ptr<EntityActionManager> ObjManager;

    std::set<std::shared_ptr<Component>> Components;
};
