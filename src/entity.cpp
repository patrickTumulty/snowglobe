
#include "entity.hpp"
#include <cerrno>
#include <cstdint>
#include <typeindex>

#define s_ptr_typeid(TYPE) typeid(*(TYPE).get())

Entity::Entity(uint32_t uid) : Entity(uid, {})
{
}

Entity::Entity(uint32_t uid, std::initializer_list<s_ptr<Component>> components) : entityUid(uid), componentsMap()
{
    entityUid = uid;
    for (auto component : components)
    {
        registerComponent(component);
    }
}

void Entity::registerComponent(s_ptr<Component> component)
{
    std::type_index index = s_ptr_typeid(component);
    if (!componentsMap.contains(index))
    {
        component->setEntityUid(entityUid);
        componentsMap.insert_or_assign(index, component);
    }
}

void Entity::unregisterComponent(s_ptr<Component> component)
{
    componentsMap.erase(s_ptr_typeid(component));
}

bool Entity::hasComponent(s_ptr<Component> component)
{
    return componentsMap.contains(s_ptr_typeid(component));
}
