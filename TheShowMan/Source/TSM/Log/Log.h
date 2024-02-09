#pragma once

#include "../Core.h"

#include <spdlog/spdlog.h>
#include <spdlog\sinks\stdout_color_sinks.h>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/win_eventlog_sink.h"
#include "spdlog/sinks/msvc_sink.h"

namespace TSM {

	class TSM_API Log
	{
	public:
		static void initialize(void);

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		//static std::shared_ptr<spdlog::> s_ClientLo;
	};

}

// Core Log Macros
#define TSM_CORE_TRACE(...) ::TSM::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TSM_CORE_INFO(...) ::TSM::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TSM_CORE_WARN(...) ::TSM::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TSM_CORE_ERROR(...) ::TSM::Log::GetCoreLogger()->error(__VA_ARGS__)

// Window Log Macros
#define TSM_TRACE(...) ::TSM::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TSM_INFO(...) ::TSM::Log::GetClientLogger()->info(__VA_ARGS__)
#define TSM_WARN(...) ::TSM::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TSM_ERROR(...) ::TSM::Log::GetClientLogger()->error(__VA_ARGS__)
