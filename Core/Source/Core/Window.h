#pragma once

#include <string>
#include <glm/glm.hpp>

#include <Core/Renderer/GLCommon.h>
#include <Core/Common/Macro.h>

namespace Core {

	struct WindowSpecification
	{
		std::string Title;
		uint32_t Width = 1280;
		uint32_t Height = 720;
		bool IsResizeable = true;
		bool VSync = true;
	};

	class Window
	{
	public:
		Window(const WindowSpecification& specification = WindowSpecification());
		~Window();
		DELETE_COPY_ASSIGNMENT(Window);

		void Create();
		void Destroy();

		void Update();

		glm::vec2 GetFramebufferSize();

		bool ShouldClose() const;

		GLFWwindow* GetHandle() const { return m_Handle; }
	private:
		WindowSpecification m_Specification;

		GLFWwindow* m_Handle = nullptr;

	};

}