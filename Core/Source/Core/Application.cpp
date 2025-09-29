#include "Application.h"

#include <cassert>
#include <iostream>

#include <Core/Renderer/GLUtils.h>
#include <spdlog/spdlog.h>



namespace Core {

	static Application* s_Application = nullptr;

	static void GLFWErrorCallback(int error, const char* description)
	{
        SPDLOG_ERROR("[GLFW Error]: {}", description);
	}

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		s_Application = this;

		glfwSetErrorCallback(GLFWErrorCallback);
		glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		if (m_Specification.WindowSpec.Title.empty())
			m_Specification.WindowSpec.Title = m_Specification.Name;

		m_Window = std::make_shared<Window>(m_Specification.WindowSpec);
		m_Window->Create();


        RegisterEventCallback();

		Renderer::Utils::InitOpenGLDebugMessageCallback();
	}

	Application::~Application()
	{
		m_Window->Destroy();

		glfwTerminate();

		s_Application = nullptr;
	}

	void Application::Run()
	{
		m_Running = true;

		float lastTime = GetTime();
        auto window = m_Window->GetHandle();

		while (m_Running)
		{
			glfwPollEvents();
            
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

			if (m_Window->ShouldClose())
			{
				Stop();
				break;
			}

			float currentTime = GetTime();
			float timestep = glm::clamp(currentTime - lastTime, 0.001f, 0.1f);
			lastTime = currentTime;

			for (const std::unique_ptr<Layer>& layer : m_LayerStack)
				layer->OnUpdate(timestep);

			for (const std::unique_ptr<Layer>& layer : m_LayerStack)
				layer->OnRender();

			m_Window->Update();
		}
	}

	void Application::Stop()
	{
		m_Running = false;
	}

	glm::vec2 Application::GetFramebufferSize() const
	{
		return m_Window->GetFramebufferSize();
	}

	Application& Application::Get()
	{
		assert(s_Application);
		return *s_Application;
	}

	float Application::GetTime()
	{
		return (float)glfwGetTime();
	}

    void Application::DispatchEvent(Event& ev) const
    {
        for (const auto& layer : m_LayerStack)
        {
            layer->OnEvent(ev);
        }
    }

    void Application::RegisterEventCallback() const
    {
        auto window = m_Window->GetHandle();

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            SPDLOG_INFO("key={} scancode={} action={} mods={}", key, scancode, action, mods);
            KeyEvent ev{key, scancode, action, mods};
            Application::Get().DispatchEvent(ev);
        });

        glfwSetWindowPosCallback(window, [](GLFWwindow* window, int xpos, int ypos) {
            WindowPosEvent ev{ xpos, ypos };
            Application::Get().DispatchEvent(ev);
        });

        glfwSetWindowMaximizeCallback(window, [](GLFWwindow* window, int maximized) {
            WindowMaximizeEvent ev{ maximized };
            Application::Get().DispatchEvent(ev);
        });

        glfwSetTitlebarHitTestCallback(window, [](GLFWwindow* window, int xpos, int ypos, int* hit) {
            TitleBarHitTestEvent ev{ xpos, ypos, hit };
            Application::Get().DispatchEvent(ev);
        });

        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
            WindowSizeEvent ev{ width, height };
            Application::Get().DispatchEvent(ev);
        });

        glfwSetWindowRefreshCallback(window, [](GLFWwindow* window) {
            WindowRefreshEvent ev;
            Application::Get().DispatchEvent(ev);
        });
        
        glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
            WindowFocusEvent ev{ focused };
            Application::Get().DispatchEvent(ev);
        });
        
        //glfwSetFramebufferSizeCallback

        //glfwSetWindowContentScaleCallback
    }
}