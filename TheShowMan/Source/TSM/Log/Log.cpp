#include "pch.h"

#include "Log.h"
#include <spdlog\sinks\stdout_color_sinks.h>

namespace TSM {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::initialize(void)
	{
		// %^	start color range (can be used only once)	"[mylogger] [info(green)] Some message"
		// %T or %X	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S	"23:55:59"
		// %v	The actual text to log	"some user text"
		// %$	end color range (for example %^[+++]%$ %v) (can be used only once)	[+++] Some message
		spdlog::set_pattern("%^[%T] %n : %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("TSM");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("OGL");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
