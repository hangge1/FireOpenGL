
#include <Core/Application.h>

#include <AppLayer.h>

int main(int argc, char* argv[])
{
    Core::ApplicationSpecification appSpec;
	appSpec.Name = "Architecture";
	appSpec.WindowSpec.Width = 800;
	appSpec.WindowSpec.Height = 600;

	Core::Application application(appSpec);
	application.PushLayer<AppLayer>();
	application.Run();
	
    return 0;
}

