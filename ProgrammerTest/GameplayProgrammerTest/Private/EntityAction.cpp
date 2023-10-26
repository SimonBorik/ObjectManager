#include "../Public/EntityAction.h"

bool EntityAction::CanBeVisible()
{
    return IsVisible;
}

void EntityAction::SetVisibility(const bool Visible)
{
    IsVisible = Visible;
}
