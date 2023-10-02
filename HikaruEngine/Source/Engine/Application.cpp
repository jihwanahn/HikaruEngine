#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace Hikaru
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HK_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HK_TRACE(e);
		}

		while (true)
		{

		}
	}
}
