#pragma once

#include "ObjectManager.h"

class EntityAction;

class EntityActionManager : public ObjectManager
{
    
public:
    explicit EntityActionManager(Entity* NewEntity) : ObjectManager(NewEntity){}

    std::vector<EntityAction*> GetVisibleActions() const;
};
