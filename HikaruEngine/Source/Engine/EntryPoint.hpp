#pragma once

#ifdef HK_PLATFORM_WINDOWS

extern Hikaru::Application* Hikaru::CreateApplication();

int main(int argc, char** argv) 
{
	Hikaru::Log::Init();
	HK_CORE_WARN("Initialized Log!");
	int major = 1;
	int minor = 0;
	HK_INFO("I'm a Logging system for your Renderer version {0}.{1}", major, minor);

	auto app = Hikaru::CreateApplication();
	app->Run();
	delete app;
}

#endif