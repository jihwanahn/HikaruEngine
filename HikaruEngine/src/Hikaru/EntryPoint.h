#pragma once

#ifdef HK_PLATFORM_WINDOWS

extern Hikaru::Application* Hikaru::CreateApplication();

int main(int argc, char** argv) 
{

	auto app = Hikaru::CreateApplication();
	app->Run();
	delete app;
}

#endif