#pragma once
#include <memory>
#include "../Entities/Entity.h"
#include "../EntityAction.h"

class ObjectManager;
class Object;
class Entity;

class Component
{

public:
    Component(Entity* Entity) : OwningEntity(Entity){}
    
    virtual ~Component() = default;

    const Entity& GetEntity() const;
    
    // Create object of a given type
    template <class ObjectType, typename... Args>
    std::shared_ptr<ObjectType> CreateObject(Args&&... args)
    {
        return std::make_shared<ObjectType>(std::forward<Args>(args)...);
    }
private:
    Entity* OwningEntity;
};
