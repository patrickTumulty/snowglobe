

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "component.hpp"
#include <cerrno>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <typeindex>
#include <unordered_map>

class Entity
{
public:
    explicit Entity(uint32_t index);
    Entity(uint32_t index, std::initializer_list<std::shared_ptr<Component>> components);

    void registerComponent(std::shared_ptr<Component> component);

    void unregisterComponent(std::shared_ptr<Component> component);

    uint32_t getEntityIndex();

    /**
     * @brief Check if entity has a particular component 
     *
     * @tparam T component type 
     *
     * @return true if has component 
     */
    template<typename T>
    bool hasComponent()
    {
        return componentsMap.contains(typeid(T));
    }

    /**
     * @brief Get Component
     *
     * @tparam T component type
     *
     * @return component or nullptr
     */
    template<typename T>
    std::shared_ptr<T> getComponent()
    {
        if (hasComponent<T>())
        {
            return std::dynamic_pointer_cast<T>(componentsMap[typeid(T)]);
        }
        return nullptr;
    }

private:
    uint32_t entityIndex;
    std::unordered_map<std::type_index, std::shared_ptr<Component>> componentsMap;
};

#endif
