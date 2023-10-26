#pragma once

#include <vector>

class Entity;
class Object;

using Objects = std::vector<Object*>;

class ObjectManager
{

public:
    ObjectManager(Entity* NewEntity) : OwningEntity(NewEntity){}
    
    size_t RegisterObject(Object* NewObject);
    
    void UnregisterObject(Object* ObjectToRemove);

    const Objects& GetObjects();

    void SetMaxObjects(int32_t NewMaxObjects);

    const Entity& GetOwningEntity() const;
    
protected:
    Objects ObjectsArray;

    // Maximum number of objects
    size_t MaxObjects = 100;

    Entity* OwningEntity;
};
