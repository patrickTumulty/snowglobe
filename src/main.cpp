
#include "component.hpp"
#include "entity_manager.hpp"
#include <app.hpp>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <locale>
#include <map>
#include <memory>
#include <ostream>
#include <sg_logging.hpp>
#include <spdlog/sinks/rotating_file_sink.h>
#include <strings.h>
#include <typeindex>
#include <unordered_map>
#include <utility>
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
};

class ComponentB : public Component
{
public:
    int value;
    std::string name;
};

class ComponentC : public Component
{
public:
    int value;
    std::string name;
};

int main()
{
    initLogging("logs/snowglobe.log");

    printf("Hello, World\n");


}

