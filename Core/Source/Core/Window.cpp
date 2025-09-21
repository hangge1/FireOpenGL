#include "Core/Window.h"

#include <cassert>
#include <spdlog/spdlog.h>

namespace Core {

	Window::Window(const WindowSpecification& specification)
		: m_Specification(specification)
	{
	}

	Window::~Window()
	{
		Destroy();
	}

	void Window::Create()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		m_Handle = glfwCreateWindow(m_Specification.Width, m_Specification.Height,
			m_Specification.Title.c_str(), nullptr, nullptr);

		if (!m_Handle)
		{
			glfwTerminate();
		    SPDLOG_CRITICAL("Failed to create GLFW window!");
			assert(false);
		}

		glfwMakeContextCurrent(m_Handle);
		glfwSwapInterval(m_Specification.VSync ? 1 : 0);

#ifdef GLAD_OPTION_GL_MX
	    GladGLContext context = {};
#ifdef GLAD_OPTION_GL_LOADER
	    int version = gladLoaderLoadGLContext(&context);
#else
	    int version = gladLoadGLContext(&context, glfwGetProcAddress);
#endif
#else
#ifdef GLAD_OPTION_GL_LOADER
	    int version = gladLoaderLoadGL();
#else
	    int version = gladLoadGL(glfwGetProcAddress);
#endif
#endif

        if (version == 0)
        {
            SPDLOG_CRITICAL("Failed to initialize OpenGL context");
            assert(false);
        }

        SPDLOG_INFO("Loaded OpenGL {}.{}", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
	}

	void Window::Destroy()
	{
		if (m_Handle)
			glfwDestroyWindow(m_Handle);

		m_Handle = nullptr;
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Handle);
	}

	glm::vec2 Window::GetFramebufferSize()
	{
		int width, height;
		glfwGetFramebufferSize(m_Handle, &width, &height);
		return { width, height };
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Handle) != 0;
	}

}