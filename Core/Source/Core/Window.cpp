#include "Core/Window.h"

#include <cassert>
#include <Core/Log/Log.h>

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
		m_Handle = glfwCreateWindow(m_Specification.Width, m_Specification.Height,
			m_Specification.Title.c_str(), nullptr, nullptr);

		if (!m_Handle)
		{
			glfwTerminate();
            LOG_CRITICAL("Failed to create GLFW window!");
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
            LOG_CRITICAL("Failed to initialize OpenGL context");
            assert(false);
        }

        LOG_INFO("Loaded OpenGL {}.{}", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
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