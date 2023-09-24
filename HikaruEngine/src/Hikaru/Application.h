#pragma once

#include "Core.h"

namespace Hikaru
{
	class HIKARU_API Application
	{
	public:
				Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
