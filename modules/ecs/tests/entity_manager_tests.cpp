#include "entity_manager.hpp"
#include "test_components.hpp"
#include <cstdint>
#include <cstdio>
#include <gtest/gtest.h>
#include <memory>

static void addDefaultEntities(EntityManager &entityManager)
{
    entityManager.newEntity({std::make_shared<ComponentA>(),
                             std::make_shared<ComponentB>(),
                             std::make_shared<ComponentC>()});

    entityManager.newEntity({std::make_shared<ComponentA>(),
                             std::make_shared<ComponentB>(),
                             std::make_shared<ComponentC>()});

    entityManager.newEntity({std::make_shared<ComponentA>(),
                             std::make_shared<ComponentB>()});

    entityManager.newEntity({std::make_shared<ComponentA>(),
                             std::make_shared<ComponentB>()});

    entityManager.newEntity({std::make_shared<ComponentA>()});
}

TEST(EntityManagerTests, QuerySingleComponentsTest)
{
    EntityManager entityManager;

    addDefaultEntities(entityManager);

    auto components = entityManager.queryEntities<ComponentA>();
    ASSERT_EQ(components.size(), 5);

    std::set<uint32_t> uidSet;
    for (auto components : components)
    {
        uidSet.insert(components->getEntityIndex());
    }

    ASSERT_EQ(uidSet.size(), components.size());
}

TEST(EntityManagerTests, QueryDoubleComponentsTest)
{
    EntityManager entityManager;

    addDefaultEntities(entityManager);

    auto components = entityManager.queryEntities<ComponentA, ComponentB>();
    ASSERT_EQ(components.size(), 4);

    std::set<uint32_t> uidSet;
    for (auto [componentA, componentB] : components)
    {
        ASSERT_EQ(componentA->getEntityIndex(), componentB->getEntityIndex());
        uidSet.insert(componentA->getEntityIndex());
    }

    ASSERT_EQ(uidSet.size(), components.size());
}

TEST(EntityManagerTests, QueryTripleComponentsTest)
{
    EntityManager entityManager;

    addDefaultEntities(entityManager);

    auto components = entityManager.queryEntities<ComponentA, ComponentB, ComponentC>();
    ASSERT_EQ(components.size(), 2);

    std::set<uint32_t> uidSet;
    for (auto [componentA, componentB, componentC] : components)
    {
        ASSERT_EQ(componentA->getEntityIndex(), componentB->getEntityIndex());
        ASSERT_EQ(componentB->getEntityIndex(), componentC->getEntityIndex());
        uidSet.insert(componentA->getEntityIndex());
    }

    ASSERT_EQ(uidSet.size(), components.size());
}

TEST(EntityManagerTests, AddComponentTest)
{
    EntityManager entityManager;

    addDefaultEntities(entityManager);

    auto components3 = entityManager.queryEntities<ComponentA, ComponentB, ComponentC>();
    ASSERT_EQ(components3.size(), 2);

    auto components2 = entityManager.queryEntities<ComponentA, ComponentB>();
    ASSERT_EQ(components2.size(), 4);

    for (auto [componentA, componentB] : components2)
    {
        if (!entityManager.entityHasComponent<ComponentC>(componentA->getEntityIndex()))
        {
            entityManager.addComponent(componentA->getEntityIndex(), std::make_shared<ComponentC>());
        }
    }

    components3 = entityManager.queryEntities<ComponentA, ComponentB, ComponentC>();
    ASSERT_EQ(components3.size(), 4);
}

TEST(EntityManagerTests, RemoveComponentTest)
{
    EntityManager entityManager;

    addDefaultEntities(entityManager);

    auto components3 = entityManager.queryEntities<ComponentA, ComponentB, ComponentC>();
    ASSERT_EQ(components3.size(), 2);

    for (auto [componentA, componentB, componentC] : components3)
    {
        if (entityManager.entityHasComponent<ComponentC>(componentA->getEntityIndex()))
        {
            entityManager.removeComponent(componentA->getEntityIndex(), componentC);
        }
    }

    components3 = entityManager.queryEntities<ComponentA, ComponentB, ComponentC>();
    ASSERT_EQ(components3.size(), 0);
}
