#include "sg_logging.hpp"
#include <cstdarg>
#include <fmt/core.h>
#include <memory>
#include <spdlog/common.h>
#include <spdlog/details/registry.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

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
        spdlog::register_logger(logger);
        spdlog::set_default_logger(logger);
    }
}

std::shared_ptr<spdlog::logger> getLogger()
{
    return logger;
}

