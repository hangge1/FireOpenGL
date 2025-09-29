
#pragma once

#include "Layer.h"
#include "Window.h"

#include <glm/glm.hpp>

#include <string>
#include <memory>
#include <vector>

namespace Core {

	struct ApplicationSpecification
	{
		std::string Name = "Application";
		WindowSpecification WindowSpec;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification = ApplicationSpecification());
		~Application();

		void Run();
		void Stop();

		template <typename TLayer, typename = std::enable_if_t<std::is_base_of_v<Layer, TLayer>>>
		void PushLayer()
		{
			m_LayerStack.push_back(std::make_unique<TLayer>());
		}

		glm::vec2 GetFramebufferSize() const;

		static Application& Get();
		static float GetTime();

    protected:
        void DispatchEvent(Event& ev) const;

        void RegisterEventCallback() const;
	private:
		ApplicationSpecification m_Specification;
		std::shared_ptr<Window> m_Window;
		bool m_Running = false;

		std::vector<std::unique_ptr<Layer>> m_LayerStack;
	};

}