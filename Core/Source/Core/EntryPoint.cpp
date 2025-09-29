

#include <Core/Application.h>

extern Core::Application* CreateApplication();

int main(int argc, char* argv[])
{
    Core::Application* application = CreateApplication();
    application->Run();
    delete application;
	
    return 0;
}
