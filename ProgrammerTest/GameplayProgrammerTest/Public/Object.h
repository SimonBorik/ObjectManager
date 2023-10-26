#pragma once

#include "Managers/ObjectManager.h"

class ObjectManager;

class Object
{
public:
    Object(ObjectManager* NewManager);
    
    virtual ~Object();

    size_t GetObjectId() const;

    virtual void Execute();

private:
    ObjectManager* Manager;

    // Objects have unique ID within the same object manager
    size_t ObjectId;
};
