#pragma once

#include "EngineUtil.h"
#include "pch.h"

#define ENGINE_FRAMERATE 60

namespace Engine
{
	class ENGINE_API EngineApp
	{
	public:
		void Run();
		virtual void OnUpdate();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / ENGINE_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
