#pragma once

#include <Core/Renderer/GLApi.h>
#include <Core/Event/Event.h>
#include <Core/Event/WindowSizeEvent.h>
#include <Core/Common/Macro.h>

namespace Core {

	class Layer
	{
	public:
        Layer() = default;
		virtual ~Layer() = default;
		DELETE_COPY_ASSIGNMENT(Layer);

        virtual bool Init(){ return true; }

        virtual void Destroy(){}

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