
#include "entity_manager.hpp"
#include "entity.hpp"
#include <cstdarg>
#include <initializer_list>
#include <memory>

void EntityManager::newEntity(std::initializer_list<std::shared_ptr<Component>> components)
{
    std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(uidCounter++, components);
    entities.push_back(newEntity);
}

void EntityManager::addComponent(uint32_t entityUid, std::shared_ptr<Component> component)
{

}

void EntityManager::removeEntity(uint32_t entityUid)
{

}
