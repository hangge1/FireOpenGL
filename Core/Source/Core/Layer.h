#pragma once

#include <Core/Renderer/GLCommon.h>
#include <Core/Event/Event.h>
#include <Core/Event/WindowSizeEvent.h>

namespace Core {

	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnEvent(Event::Event& event) 
        {
            if (event.Type() == Event::EventType::WindowSizeEvent)
            {
                auto& ev = dynamic_cast<Event::WindowSizeEvent&>(event);
                glViewport(0, 0, ev.Width(), ev.Height());
            }
        }

		virtual void OnUpdate(float ts) {}
		virtual void OnRender() {}
	};

}