#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace FallEngine {
	class FALL_API Log
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

#define F_CORE_TRACE(...)		::FallEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define F_CORE_INFO(...)		::FallEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define F_CORE_WARN(...)		::FallEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define F_CORE_ERROR(...)		::FallEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define F_CORE_CRITICAL(...)		::FallEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define F_TRACE(...)			::FallEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define F_INFO(...)				::FallEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define F_WARN(...)				::FallEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define F_ERROR(...)			::FallEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define F_CRITICAL(...)			::FallEngine::Log::GetClientLogger()->critical(__VA_ARGS__)