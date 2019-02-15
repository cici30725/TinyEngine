#include "pch.h"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::m_Logger;

Log::Log()
{
}


Log::~Log()
{
}

void Log::Init() {
	spdlog::set_pattern("%^[%T] %n: %v%$");
	m_Logger = spdlog::stdout_color_mt("Log");
	m_Logger->set_level(spdlog::level::trace);
}
