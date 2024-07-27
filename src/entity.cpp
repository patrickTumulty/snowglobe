
#include "entity.hpp"
#include <cerrno>

Entity::Entity() : componentsMap()
{
}

void Entity::registerComponent(std::shared_ptr<Component> component)
{
    if (!componentsMap.contains(typeid(component)))
    {
        componentsMap.insert_or_assign(typeid(component), component);
    }
}

void Entity::unregisterComponent(std::shared_ptr<Component> component)
{
    componentsMap.erase(typeid(component));
}

bool Entity::hasComponent(std::shared_ptr<Component> component)
{
    return componentsMap.contains(typeid(component));
}
