#include "../../Public/Components/Component.h"

const Entity& Component::GetEntity() const
{
    return *OwningEntity;
}
