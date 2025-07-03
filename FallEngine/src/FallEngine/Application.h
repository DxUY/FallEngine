#pragma once

#include "Core.h"

namespace FallEngine {
	class FALL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in CLIENT
	Application* CreateApplication();
}