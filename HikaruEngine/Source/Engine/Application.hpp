#pragma once

#include "Core.hpp"
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Window.hpp"

namespace Hikaru
{
	class HIKARU_API Application
	{
	public:
				Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}
