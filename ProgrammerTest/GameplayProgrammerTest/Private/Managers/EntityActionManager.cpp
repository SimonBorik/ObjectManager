#include "../../Public/Managers/EntityActionManager.h"

#include "../../Public/EntityAction.h"

std::vector<EntityAction*> EntityActionManager::GetVisibleActions() const
{
    std::vector<EntityAction*> VisibleActions;
    for (const auto& Obj : ObjectsArray)
    {
        auto* Action = dynamic_cast<EntityAction*>(Obj);
        if (Action && Action->CanBeVisible())
        {
            VisibleActions.emplace_back(Action);
        }
    }
    
    return VisibleActions;
}
