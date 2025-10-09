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
#include <Core/Interactor/PerspectiveCamera.h>

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

    std::shared_ptr<PerspectiveCamera> m_camera;

    glm::vec3 m_CameraMove;

    Core::Renderer::VAO m_vao;
    Core::Renderer::VBO m_vbo;
    Core::Renderer::EBO m_ebo;
};
