
#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "component.hpp"
#include "entity.hpp"
#include "sgtypes.hpp"
#include <cstdint>
#include <memory>
#include <vector>

class EntityManager
{
public:
    EntityManager() = default;

    void newEntity(std::initializer_list<s_ptr<Component>> components);

    void addComponent(uint32_t entityUid, s_ptr<Component> component);

    void removeEntity(uint32_t entityUid);

    template<typename T> std::vector<s_ptr<T>> queryEntities()
    {
        std::vector<s_ptr<T>> collection;
        for (auto entity : entities)
        {
            s_ptr<T> t = entity->getComponent<T>();
            if (t == nullptr)
            {
                continue;
            }

            collection.push_back(t);
        }
        return collection;
    }

    // template<typename T, typename V> std::vector<std::tuple<s_ptr<T> &, s_ptr<V> &>> queryEntities()
    // {
    //     std::vector<std::tuple<s_ptr<T> &, s_ptr<V> &>> collection;
    //     for (auto entity : entities)
    //     {
    //         auto t = entity->getComponent<T>();
    //         if (!t.has_value())
    //         {
    //             continue;
    //         }
    //
    //         auto v = entity->getComponent<V>();
    //         if (!v.has_value())
    //         {
    //             continue;
    //         }
    //
    //         collection.push_back({t.value(), v.value()});
    //     }
    //     return collection;
    // }

    // template<typename T, typename V, typename K>
    // std::vector<std::tuple<s_ptr<T> &, s_ptr<V> &, s_ptr<K> &>> queryEntities()
    // {
    //     std::vector<std::tuple<s_ptr<T> &, s_ptr<V> &, s_ptr<K> &>> collection;
    //     for (auto entity : entities)
    //     {
    //         s_ptr<T> &t = entity->getComponent<T>();
    //         if (t == nullptr)
    //         {
    //             continue;
    //         }
    //
    //         s_ptr<V> &v = entity->getComponent<V>();
    //         if (v == nullptr)
    //         {
    //             continue;
    //         }
    //
    //         s_ptr<K> &k = entity->getComponent<K>();
    //         if (k == nullptr)
    //         {
    //             continue;
    //         }
    //
    //         collection.push_back({t, v, k});
    //     }
    //     return collection;
    // }

private:
    uint32_t uidCounter = 0;
    std::vector<std::shared_ptr<Entity>> entities;
};

#endif
