

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "component.hpp"
#include "sgtypes.hpp"
#include <cerrno>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <memory>
#include <optional>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

class Entity
{
public:
    explicit Entity(uint32_t uid);
    Entity(uint32_t uid, std::initializer_list<s_ptr<Component>> components);

    void registerComponent(s_ptr<Component> component);

    void unregisterComponent(s_ptr<Component> component);

    bool hasComponent(s_ptr<Component> component);

    template<typename T> s_ptr<T> getComponent()
    {
        return std::dynamic_pointer_cast<T>(componentsMap[typeid(T)]);
    }

private:
    uint32_t entityUid;
    std::unordered_map<std::type_index, std::shared_ptr<Component>> componentsMap;
};

#endif
