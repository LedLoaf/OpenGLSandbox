#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GLCore {

	class Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getLogger() { return s_logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_logger;
	};

}

// Client log macros
#define LOG_TRACE(...)         ::GLCore::Log::getLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::GLCore::Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::GLCore::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::GLCore::Log::getLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::GLCore::Log::getLogger()->critical(__VA_ARGS__)
