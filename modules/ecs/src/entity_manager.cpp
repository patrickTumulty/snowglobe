
#include "entity_manager.hpp"
#include "entity.hpp"
#include <cstdarg>
#include <cstdint>
#include <initializer_list>
#include <memory>
#include <optional>

void EntityManager::newEntity(std::initializer_list<std::shared_ptr<Component>> components)
{
    uint32_t index = 0;
    if (!availableIndexSet.empty())
    {
        index = *availableIndexSet.begin();
        availableIndexSet.erase(availableIndexSet.begin());
    }
    else
    {
        index = entities.size();
    }
    std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(index, components);
    entities.insert(entities.begin() + index, newEntity);
}

void EntityManager::addComponent(uint32_t entityIndex, std::shared_ptr<Component> component)
{
    auto entityOptional = findEntity(entityIndex);
    if (entityOptional.has_value())
    {
        entityOptional.value()->registerComponent(component);
    }
}

void EntityManager::removeComponent(uint32_t entityIndex, std::shared_ptr<Component> component)
{
    auto entityOptional = findEntity(entityIndex);
    if (entityOptional.has_value())
    {
        entityOptional.value()->unregisterComponent(component);
    }
}

void EntityManager::removeEntity(uint32_t entityIndex)
{
    auto entityOptional = findEntity(entityIndex);
    if (entityOptional.has_value())
    {
        entities[entityIndex] = nullptr;
        availableIndexSet.insert(entityIndex);
    }
}

std::optional<std::shared_ptr<Entity>> EntityManager::findEntity(uint32_t entityIndex)
{
    if (entityIndex >= entities.size())
    {
        return std::nullopt;
    }

    return entities[entityIndex];
}
