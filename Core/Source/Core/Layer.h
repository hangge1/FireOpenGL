#pragma once

#include "Event.h"
#include <Core/Renderer/GLCommon.h>

namespace Core {

	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnEvent(Event& event) 
        {
            if (event.Type() == EventType::WindowSizeEvent)
            {
                auto& ev = dynamic_cast<WindowSizeEvent&>(event);
                glViewport(0, 0, ev.Width(), ev.Height());
            }
        }

		virtual void OnUpdate(float ts) {}
		virtual void OnRender() {}
	};

}