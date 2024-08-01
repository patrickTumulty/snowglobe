
#include "entity_manager.hpp"
#include "entity.hpp"
#include <algorithm>
#include <cstdarg>
#include <initializer_list>
#include <memory>
#include <optional>

void EntityManager::newEntity(std::initializer_list<std::shared_ptr<Component>> components)
{
    std::shared_ptr<Entity> newEntity = std::make_shared<Entity>(uidCounter++, components);
    entities.push_back(newEntity);
}

void EntityManager::addComponent(uint32_t entityUid, std::shared_ptr<Component> component)
{
    auto entityIter = findEntity(entityUid);
    if (entityIter.has_value())
    {
        (*entityIter.value())->registerComponent(component);
    }
}

void EntityManager::removeEntity(uint32_t entityUid)
{
    auto entityIter = findEntity(entityUid);
    if (entityIter.has_value())
    {
        entities.erase(entityIter.value());
    }
}


std::optional<std::vector<std::shared_ptr<Entity>>::iterator> EntityManager::findEntity(uint32_t entityUid)
{
    auto iter = std::find_if(entities.begin(), entities.end(), [entityUid](std::shared_ptr<Entity> entity) {
        return entity->getEntityUid() == entityUid;
    });
    return (iter == entities.end()) ? std::nullopt : std::optional<std::vector<std::shared_ptr<Entity>>::iterator>{iter};
}
