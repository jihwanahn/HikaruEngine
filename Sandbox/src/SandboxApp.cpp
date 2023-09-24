#include <Hikaru.h>
#include <memory>


class Sandbox : public Hikaru::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Hikaru::Application* Hikaru::CreateApplication()
{
	return new Sandbox();
} 