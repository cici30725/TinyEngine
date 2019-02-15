#pragma once
#include <memory>
#include "spdlog/spdlog.h"

class Log
{
public:
	Log();
	~Log();
	static void Init();
	static inline std::shared_ptr<spdlog::logger>& GetLogger() { return m_Logger; }
private:
	static std::shared_ptr<spdlog::logger> m_Logger;
};

// Log macros
#define TRACE(...)	      Log::GetLogger()->trace(__VA_ARGS__)
#define INFO(...)	      Log::GetLogger()->info(__VA_ARGS__)
#define WARN(...)	      Log::GetLogger()->warn(__VA_ARGS__)
#define ERROR(...)	      Log::GetLogger()->error(__VA_ARGS__)
#define FATAL(...)	      Log::GetLogger()->fatal(__VA_ARGS__)
