#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"

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
