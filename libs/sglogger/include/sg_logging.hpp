
#ifndef SG_LOGGING_HPP
#define SG_LOGGING_HPP

#include <fmt/core.h>
#include <memory>
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <string>

void initLogging(std::string filepath);

std::shared_ptr<spdlog::logger> getLogger();

#define logInfo(FMT, ARGS) SPDLOG_INFO(FMT, ARGS);
#define logWarn(FMT, ARGS) SPDLOG_WARN(FMT, ARGS);
#define logError(FMT, ARGS) SPDLOG_ERROR(FMT, ARGS);
#define logDebug(FMT, ARGS) SPDLOG_DEBUG(FMT, ARGS);
#define logBacktrace() getLogger()->dump_backtrace()

#endif
