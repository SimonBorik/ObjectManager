#include "../Public/Object.h"

#include <iostream>
#include <string>

#include "../Public/Entities/Entity.h"
#include "../Public/Managers/ObjectManager.h"

Object::Object(ObjectManager* NewManager)
{
    Manager = NewManager;
    ObjectId = Manager->RegisterObject(this);
}

Object::~Object()
{
    if (Manager)
    {
        Manager->UnregisterObject(this);
    }
}

size_t Object::GetObjectId() const
{
    return ObjectId;
}

void Object::Execute()
{
    std::cout << "Executing object ID: " + std::to_string(ObjectId) + " of Entity: " + std::to_string(Manager->GetOwningEntity().GetId())  + "\n"; 
}
