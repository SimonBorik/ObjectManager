#include "../../Public/Managers/ObjectManager.h"

#include <stdexcept>

#include "../../Public/Object.h"

size_t ObjectManager::RegisterObject(Object* NewObject)
{
    if (ObjectsArray.size() < MaxObjects)
    {
        ObjectsArray.emplace_back(NewObject);
        return ObjectsArray.size() + 1;
    }
    
    throw std::runtime_error("Objects limit reached");
}

void ObjectManager::UnregisterObject(Object* ObjectToRemove)
{
    ObjectsArray.erase(std::remove(ObjectsArray.begin(), ObjectsArray.end(), ObjectToRemove), ObjectsArray.end());
}

const Objects& ObjectManager::GetObjects()
{
    return ObjectsArray;
}

void ObjectManager::SetMaxObjects(int32_t NewMaxObjects)
{
    MaxObjects = NewMaxObjects;
}

const Entity& ObjectManager::GetOwningEntity() const
{
    return *OwningEntity;
}
