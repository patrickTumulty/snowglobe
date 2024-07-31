
#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "component.hpp"
#include "entity.hpp"
#include <cstdint>
#include <memory>
#include <vector>

class EntityManager
{
public:
    EntityManager() = default;

    void newEntity(std::initializer_list<std::shared_ptr<Component>> components);

    void addComponent(uint32_t entityUid, std::shared_ptr<Component> component);

    void removeEntity(uint32_t entityUid);

    template<typename T> std::vector<std::shared_ptr<T>> queryEntities()
    {
        std::vector<std::shared_ptr<T>> collection;
        for (auto entity : entities)
        {
            std::shared_ptr<T> t = entity->getComponent<T>();
            if (t == nullptr)
            {
                continue;
            }

            collection.push_back(t);
        }
        return collection;
    }

    template<typename T, typename V> std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>>> queryEntities()
    {
        std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>>> collection;
        for (auto entity : entities)
        {
            std::shared_ptr<T> t = entity->getComponent<T>();
            if (t == nullptr)
            {
                continue;
            }

            std::shared_ptr<V> v = entity->getComponent<V>();
            if (v == nullptr)
            {
                continue;
            }

            collection.push_back({t, v});
        }
        return collection;
    }

    template<typename T, typename V, typename K> std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>, std::shared_ptr<K>>> queryEntities()
    {
        std::vector<std::tuple<std::shared_ptr<T>, std::shared_ptr<V>, std::shared_ptr<K>>> collection;
        for (auto entity : entities)
        {
            std::shared_ptr<T> t = entity->getComponent<T>();
            if (t == nullptr)
            {
                continue;
            }

            std::shared_ptr<V> v = entity->getComponent<V>();
            if (v == nullptr)
            {
                continue;
            }

            std::shared_ptr<K> k = entity->getComponent<K>();
            if (k == nullptr)
            {
                continue;
            }

            collection.push_back({t, v, k});
        }
        return collection;
    }

private:
    uint32_t uidCounter = 0;
    std::vector<std::shared_ptr<Entity>> entities;
};

#endif
