
#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <spdlog/spdlog.h>

#define logInfo(FMT, ...) SPDLOG_INFO(FMT, __VA_ARGS__)
#define logWarn(FMT, ...) SPDLOG_WARN(FMT, __VA_ARGS__)
#define logError(FMT, ...) SPDLOG_ERROR(FMT, __VA_ARGS__)
#define logDebug(FMT, ...) SPDLOG_DEBUG(FMT, __VA_ARGS__)

#endif
