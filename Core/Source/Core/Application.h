
#pragma once

#include <string>
#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include <Core/Layer.h>
#include <Core/Window.h>
#include <Core/Common/Macro.h>


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
		DELETE_COPY_ASSIGNMENT(Application);

		void Run();
		void Stop();

		template <typename TLayer, typename = std::enable_if_t<std::is_base_of_v<Layer, TLayer>>>
		void PushLayer()
		{
            auto layer = std::make_unique<TLayer>();
            if (layer->Init())
            {
			    m_LayerStack.push_back(std::move(layer));
            }
		}

		glm::vec2 GetFramebufferSize() const;

		static Application& Get();
		static float GetTime();

    protected:
        void DispatchEvent(Event::Event& ev) const;

        void RegisterEventCallback() const;
	private:
		ApplicationSpecification m_Specification;
		std::shared_ptr<Window> m_Window;
		bool m_Running = false;

		std::vector<std::unique_ptr<Layer>> m_LayerStack;
	};

}