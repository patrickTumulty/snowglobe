

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "component.hpp"
#include <memory>
#include <typeindex>
#include <unordered_map>

class Entity
{
  public:
    Entity();

    void registerComponent(std::shared_ptr<Component> component);

    void unregisterComponent(std::shared_ptr<Component> component);

    bool hasComponent(std::shared_ptr<Component> component);

  private:
    std::unordered_map<std::type_index, std::shared_ptr<Component>> componentsMap;
};

#endif
