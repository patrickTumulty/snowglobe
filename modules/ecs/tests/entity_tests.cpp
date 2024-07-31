
#include "component.hpp"
#include "entity.hpp"
#include "test_components.hpp"
#include <gtest/gtest.h>
#include <memory>

TEST(EntityTests, EntityUidTest)
{
    Entity entity1(1, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>(), std::make_shared<ComponentC>()});
    Entity entity2(2, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()});
    Entity entity3(3, {std::make_shared<ComponentA>()});

    ASSERT_EQ(entity1.getEntityUid(), 1);
    ASSERT_EQ(entity2.getEntityUid(), 2);
    ASSERT_EQ(entity3.getEntityUid(), 3);
}

TEST(EntityTests, HasComponentTest)
{
    Entity entity1(1, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>(), std::make_shared<ComponentC>()});
    Entity entity2(2, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()});
    Entity entity3(3, {std::make_shared<ComponentA>()});

    ASSERT_TRUE(entity1.hasComponent<ComponentA>());
    ASSERT_TRUE(entity1.hasComponent<ComponentB>());
    ASSERT_TRUE(entity1.hasComponent<ComponentC>());

    ASSERT_TRUE(entity2.hasComponent<ComponentA>());
    ASSERT_TRUE(entity2.hasComponent<ComponentB>());
    ASSERT_FALSE(entity2.hasComponent<ComponentC>());

    ASSERT_TRUE(entity3.hasComponent<ComponentA>());
    ASSERT_FALSE(entity3.hasComponent<ComponentB>());
    ASSERT_FALSE(entity3.hasComponent<ComponentC>());
}

TEST(EntityTests, GetComponentTest)
{
    Entity entity1(1, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>(), std::make_shared<ComponentC>()});
    Entity entity2(2, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()});
    Entity entity3(3, {std::make_shared<ComponentA>()});

    // Entity 1
    std::shared_ptr<Component> components1[3] = {
        entity1.getComponent<ComponentA>(),
        entity1.getComponent<ComponentB>(),
        entity1.getComponent<ComponentC>(),
    };

    ASSERT_TRUE(components1[0] != nullptr);
    ASSERT_TRUE(components1[1] != nullptr);
    ASSERT_TRUE(components1[2] != nullptr);

    for (int i = 0; i < 2; i++)
    {
        if (components1[i] == nullptr)
            continue;
        ASSERT_TRUE(components1[i]->getEntityUid() == entity1.getEntityUid());
    }

    // Entity 2
    std::shared_ptr<Component> components2[3] = {
        entity2.getComponent<ComponentA>(),
        entity2.getComponent<ComponentB>(),
        entity2.getComponent<ComponentC>(),
    };

    ASSERT_TRUE(components2[0] != nullptr);
    ASSERT_TRUE(components2[1] != nullptr);
    ASSERT_FALSE(components2[2] != nullptr);

    for (int i = 0; i < 2; i++)
    {
        if (components2[i] == nullptr)
            continue;
        ASSERT_TRUE(components2[i]->getEntityUid() == entity2.getEntityUid());
    }

    // Entity 3
    std::shared_ptr<Component> components3[3] = {
        entity3.getComponent<ComponentA>(),
        entity3.getComponent<ComponentB>(),
        entity3.getComponent<ComponentC>(),
    };

    ASSERT_TRUE(components3[0] != nullptr);
    ASSERT_FALSE(components3[1] != nullptr);
    ASSERT_FALSE(components3[2] != nullptr);

    for (int i = 0; i < 3; i++)
    {
        if (components3[i] == nullptr)
            continue;
        ASSERT_TRUE(components3[i]->getEntityUid() == entity3.getEntityUid());
    }
}

TEST(EntityTests, RemoveComponentTest)
{
    Entity entity1(1, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()});

    ASSERT_TRUE(entity1.hasComponent<ComponentA>());

    auto component = entity1.getComponent<ComponentA>();
    entity1.unregisterComponent(component);

    ASSERT_FALSE(entity1.hasComponent<ComponentA>());
}

TEST(EntityTests, AddComponentTest)
{
    Entity entity1(1, {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()});

    ASSERT_FALSE(entity1.hasComponent<ComponentC>());

    entity1.registerComponent(std::make_shared<ComponentC>());

    ASSERT_TRUE(entity1.hasComponent<ComponentC>());
}
