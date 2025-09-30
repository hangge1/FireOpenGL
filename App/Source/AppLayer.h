#pragma once

#include <cstdint>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Core/Layer.h"
#include <Core/Event/Event.h>

#include <Core/Renderer/VAO.h>
#include <Core/Renderer/VBO.h>
#include <Core/Renderer/EBO.h>
#include <Core/Renderer/ShaderProgram.h>
#include <Core/Renderer/Texture2D.h>

class AppLayer : public Core::Layer
{
public:
    virtual bool Init() override;

    virtual void OnEvent(Core::Event::Event& event) override;
	virtual void OnUpdate(float ts) override;
	virtual void OnRender() override;
private:
    std::unique_ptr<Core::Renderer::ShaderProgram> m_ShaderProgram;
    std::unique_ptr<Core::Renderer::Texture2D> m_Texture;

    glm::vec3 origin {};
    glm::vec3 lookAt {0.0f,0.0f,-1.0f};
    glm::vec3 up { 0.0f, 1.0f, 0.0f};

    Core::Renderer::VAO m_vao;
    Core::Renderer::VBO m_vbo;
    Core::Renderer::EBO m_ebo;
};
