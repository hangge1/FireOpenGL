#pragma once

#include <cstdint>

#include "Core/Layer.h"
#include "Core/Event/Event.h"

class AppLayer : public Core::Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

    virtual void OnEvent(Core::Event::Event& event) override;
	virtual void OnUpdate(float ts) override;
	virtual void OnRender() override;
private:
	uint32_t m_Shader = 0;
	uint32_t m_VertexArray = 0;
	uint32_t m_VertexBuffer = 0;
	uint32_t m_IndexBuffer = 0;
};
