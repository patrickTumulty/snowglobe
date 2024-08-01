#include "entity_manager.hpp"
#include "test_components.hpp"
#include <cstdint>
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
        uidSet.insert(components->getEntityUid());
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
        ASSERT_EQ(componentA->getEntityUid(), componentB->getEntityUid());
        uidSet.insert(componentA->getEntityUid());
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
        ASSERT_EQ(componentA->getEntityUid(), componentB->getEntityUid());
        ASSERT_EQ(componentB->getEntityUid(), componentC->getEntityUid());
        uidSet.insert(componentA->getEntityUid());
    }

    ASSERT_EQ(uidSet.size(), components.size());
}
