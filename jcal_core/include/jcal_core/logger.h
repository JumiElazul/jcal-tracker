#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "jcal_core/core.h"
#include <spdlog/spdlog.h>
#include <string>

#define JUMI_TRACE(...)    SPDLOG_LOGGER_TRACE   (jumi::Logger::get_logger(), __VA_ARGS__)
#define JUMI_DEBUG(...)    SPDLOG_LOGGER_DEBUG   (jumi::Logger::get_logger(), __VA_ARGS__)
#define JUMI_INFO(...)     SPDLOG_LOGGER_INFO    (jumi::Logger::get_logger(), __VA_ARGS__)
#define JUMI_WARN(...)     SPDLOG_LOGGER_WARN    (jumi::Logger::get_logger(), __VA_ARGS__)
#define JUMI_ERROR(...)    SPDLOG_LOGGER_ERROR   (jumi::Logger::get_logger(), __VA_ARGS__)
#define JUMI_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(jumi::Logger::get_logger(), __VA_ARGS__)

namespace jumi
{
    constexpr int LOGMAP_SIZE = 7;

	class JUMI_API Logger
	{
    public:
		static std::shared_ptr<spdlog::logger> get_logger();
		static void init();

	private:
        static bool _initialized;

		static std::shared_ptr<spdlog::logger> _core_logger;
		static std::string _log_level_map[LOGMAP_SIZE];

		static void initialize_log_map();
		static std::string get_log_level(int log_level);
	};

}
