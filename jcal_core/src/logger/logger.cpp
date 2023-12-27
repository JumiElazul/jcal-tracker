#include "jcal_core/logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <string>

namespace jumi
{

    bool Logger::_initialized = false;

	std::shared_ptr<spdlog::logger> Logger::_core_logger;
	std::string Logger::_log_level_map[LOGMAP_SIZE];

    std::shared_ptr<spdlog::logger> Logger::get_logger()
    {
        if (!_initialized)
        {
            throw std::runtime_error("Logger not initialized, can't get logger");
            return nullptr;
        }

        return _core_logger; 
    }

	void Logger::init()
	{
        if (_initialized) return;

		initialize_log_map();

		spdlog::set_pattern("%^%-8n[%T] [%-20s : %4#]: %v%$");
        _core_logger = spdlog::get("[JUMI]");

        if (!_core_logger)
        {
            _core_logger = spdlog::stdout_color_mt("[JUMI]");
        }

		_core_logger->set_level(spdlog::level::trace);
		int log_level = static_cast<int>(_core_logger->level());

        // This needs to happen before the calls below to avoid infinite recursion
        Logger::_initialized = true;

		JUMI_TRACE("Logger initialized with level: [{}]", get_log_level(log_level));
		JUMI_TRACE("TRACE MESSAGE");
		JUMI_DEBUG("DEBUG MESSAGE");
		JUMI_INFO("INFO MESSAGE");
		JUMI_WARN("WARN MESSAGE");
		JUMI_ERROR("ERROR MESSAGE");
		JUMI_CRITICAL("CRITICAL MESSAGE");
	}

	void Logger::initialize_log_map()
	{
		_log_level_map[SPDLOG_LEVEL_TRACE] =    "TRACE";
		_log_level_map[SPDLOG_LEVEL_DEBUG] =    "DEBUG";
		_log_level_map[SPDLOG_LEVEL_INFO] =     "INFO";
		_log_level_map[SPDLOG_LEVEL_WARN] =     "WARN";
		_log_level_map[SPDLOG_LEVEL_ERROR] =    "ERROR";
		_log_level_map[SPDLOG_LEVEL_CRITICAL] = "CRITICAL";
		_log_level_map[SPDLOG_LEVEL_OFF] =      "OFF";
	}

	std::string Logger::get_log_level(int log_level)
	{
		return _log_level_map[log_level];
	}

}
