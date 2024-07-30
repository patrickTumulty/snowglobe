
#include "component.hpp"
#include "entity_manager.hpp"
#include <app.hpp>
#include <cstdio>
#include <iostream>
#include <memory>
#include <sg_logging.hpp>
#include <spdlog/sinks/rotating_file_sink.h>
#include <strings.h>
#include <typeindex>
#include <vector>

static std::shared_ptr<spdlog::logger> logger = nullptr;

void initLogging(std::string filepath)
{
    if (logger == nullptr)
    {
        // Create a file rotating logger with 5 MB size max and 3 rotated files
        auto max_size = 1048576 * 5;
        auto max_files = 3;
        logger = spdlog::rotating_logger_mt("sg_logger", filepath, max_size, max_files);
        logger->set_level(spdlog::level::debug);
        logger->set_pattern("[%D-%H:%M:%S.%e](%20s:%4#)[%t:%P][%7l] %v");
        spdlog::set_default_logger(logger);
    }
}

class ComponentA : public Component
{
public:
    int value;
    std::string name;

    ComponentA(int value, std::string name) : value(value), name(name)
    {
    }
};

class ComponentB : public Component
{
public:
    int value;
    std::string name;

    ComponentB(int value, std::string name) : value(value), name(name)
    {
    }
};

class ComponentC : public Component
{
public:
    int value;
    std::string name;

    ComponentC(int value, std::string name) : value(value), name(name)
    {
    }
};

int main()
{
    initLogging("logs/snowglobe.log");

    EntityManager entityManager;

    entityManager.newEntity({
        std::make_shared<ComponentA>(1, "A1"),
        std::make_shared<ComponentB>(2, "B1"),
        std::make_shared<ComponentC>(3, "C1"),
    });

    entityManager.newEntity({
        std::make_shared<ComponentA>(4, "A2"),
        std::make_shared<ComponentB>(5, "B2"),
    });

    entityManager.newEntity({
        std::make_shared<ComponentA>(6, "A3"),
    });

    entityManager.newEntity({
        std::make_shared<ComponentC>(7, "C4"),
        std::make_shared<ComponentB>(8, "B4"),
    });

    auto entities = entityManager.queryEntities<ComponentA>();
    for (auto e : entities)
    {
        printf("%s %d: id=%d\n", e->name.c_str(), e->value, e->getEntityUid());
    }

    s_ptr<ComponentA> ca = std::make_shared<ComponentA>(1, "A");
    s_ptr<ComponentB> cb = std::make_shared<ComponentB>(2, "B");

    printf("%zu %zu\n", typeid(ca).hash_code(), typeid(cb).hash_code());

}
