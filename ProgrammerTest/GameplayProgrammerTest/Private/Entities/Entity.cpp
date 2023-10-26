#include "../../Public/Entities/Entity.h"

size_t Entity::GetId() const
{
    return Id;
}

EntityActionManager* Entity::GetObjectManager() const
{
    return ObjManager.get();
}
