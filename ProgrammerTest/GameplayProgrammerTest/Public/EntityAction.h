#pragma once

#include "Object.h"
#include "Components/Component.h"

class EntityAction : public Object
{

public:
    EntityAction(ObjectManager* Manager) : Object(Manager){}
    
    EntityAction(ObjectManager* Manager, const bool Visible) : Object(Manager), IsVisible(Visible) {}
    
    EntityAction(ObjectManager* Manager, const bool Visible, Component* ByComponent)
        : Object(Manager), IsVisible(Visible), Comp(ByComponent){}
    
    virtual bool CanBeVisible();

    void SetVisibility(bool Visible);
    
    bool IsVisible = true;

    Component* Comp{};
};
