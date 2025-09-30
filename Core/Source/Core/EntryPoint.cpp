

#include <Core/Application.h>

extern Core::Application* CreateApplication();

int main(int argc, char* argv[])
{
    Core::Application* application = CreateApplication();
    if (application)
    {
        application->Run();
        delete application;
    }
	
    return 0;
}
