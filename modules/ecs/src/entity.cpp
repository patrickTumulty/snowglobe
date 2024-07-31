
#include "entity.hpp"
#include <cerrno>

Entity::Entity(uint32_t uid) : Entity(uid, {})
{
}

Entity::Entity(uint32_t uid, std::initializer_list<std::shared_ptr<Component>> components) : entityUid(uid), componentsMap()
{
    entityUid = uid;
    for (auto component : components)
    {
        registerComponent(component);
    }
}

void Entity::registerComponent(std::shared_ptr<Component> component)
{
    auto& c = *component.get();
    std::type_index index = typeid(c);
    if (!componentsMap.contains(index))
    {
        component->setEntityUid(entityUid);
        componentsMap.insert_or_assign(index, component);
    }
}

void Entity::unregisterComponent(std::shared_ptr<Component> component)
{
    auto& c = *component.get();
    componentsMap.erase(typeid(c));
}


uint32_t Entity::getEntityUid()
{
    return entityUid;
}
