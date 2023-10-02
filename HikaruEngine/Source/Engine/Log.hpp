#pragma once

#include <memory>

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hikaru
{
	class HIKARU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros

#define HK_CORE_TRACE(...)		::Hikaru::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HK_CORE_DEBUG(...)		::Hikaru::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define HK_CORE_INFO(...)		::Hikaru::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HK_CORE_WARN(...)		::Hikaru::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HK_CORE_ERROR(...)		::Hikaru::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HK_CORE_CRITICAL(...)	::Hikaru::Log::GetCoreLogger()->critical(__VA_ARGS__)


// Client log macros

#define HK_TRACE(...)			::Hikaru::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HK_DEBUG(...)			::Hikaru::Log::GetClientLogger()->debug(__VA_ARGS__)
#define HK_INFO(...)			::Hikaru::Log::GetClientLogger()->info(__VA_ARGS__)
#define HK_WARN(...)			::Hikaru::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HK_ERROR(...)			::Hikaru::Log::GetClientLogger()->error(__VA_ARGS__)
#define HK_CRITICAL(...)		::Hikaru::Log::GetClientLogger()->critical(__VA_ARGS__)
