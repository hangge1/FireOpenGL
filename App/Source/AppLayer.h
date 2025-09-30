#pragma once

#include <cstdint>

#include "Core/Layer.h"
#include <Core/Event/Event.h>

#include <Core/Renderer/VAO.h>
#include <Core/Renderer/VBO.h>
#include <Core/Renderer/EBO.h>
#include <Core/Renderer/ShaderProgram.h>

class AppLayer : public Core::Layer
{
public:
	AppLayer();
	virtual ~AppLayer();

    virtual void OnEvent(Core::Event::Event& event) override;
	virtual void OnUpdate(float ts) override;
	virtual void OnRender() override;
private:
	std::unique_ptr<ShaderProgram> m_ShaderProgram;

    VAO m_vao;
    VBO m_vbo;
    EBO m_ebo;
};
