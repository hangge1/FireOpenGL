
#include <Core/Application.h>
#include <AppLayer.h>

Core::Application* CreateApplication()
{
	Core::ApplicationSpecification appSpec;
	appSpec.Name = "FireOpenGL";
	appSpec.WindowSpec.Width = 800;
	appSpec.WindowSpec.Height = 600;

	Core::Application* application = new Core::Application(appSpec);
	application->PushLayer<AppLayer>();
    return application;
}

