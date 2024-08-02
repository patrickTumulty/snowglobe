
#include "entity.hpp"
#include <cerrno>

Entity::Entity(uint32_t index) : Entity(index, {})
{
}

Entity::Entity(uint32_t index, std::initializer_list<std::shared_ptr<Component>> components) : entityIndex(index), componentsMap()
{
    entityIndex = index;
    for (auto component : components)
    {
        registerComponent(component);
    }
}

void Entity::registerComponent(std::shared_ptr<Component> component)
{
    auto &c = *component.get();
    std::type_index typeIndex = typeid(c);
    if (!componentsMap.contains(typeIndex))
    {
        component->setEntityIndex(entityIndex);
        componentsMap.insert_or_assign(typeIndex, component);
    }
}

void Entity::unregisterComponent(std::shared_ptr<Component> component)
{
    auto &c = *component.get();
    componentsMap.erase(typeid(c));
}


uint32_t Entity::getEntityIndex()
{
    return entityIndex;
}
