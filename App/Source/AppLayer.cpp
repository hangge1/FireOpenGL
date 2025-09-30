#include "AppLayer.h"

#include <cassert>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>

#include <Core/Common/Macro.h>
#include <Core/Application.h>
#include <Core/Renderer/VBLayout.h>
#include <Core/Renderer/ShaderProgramUtils.h>
#include <Core/Renderer/TextureUtils.h>

using namespace Core;
using namespace Core::Renderer;

bool AppLayer::Init()
{
    m_ShaderProgram = ShaderProgramUtils::CreateShaderProgramFromFile(
        SHADER_PATH(Vertex.glsl), SHADER_PATH(Fragment.glsl));
    if (!m_ShaderProgram)
    {
        SPDLOG_CRITICAL("Failed to Create ShaderProgram");
        return false;
    }

    m_Texture = TextureUtils::CreateTexture2DFromFile(TEXTURE_PATH(Copilot.png));
    if (!m_Texture)
    {
        SPDLOG_CRITICAL("Failed to Create Texture2D");
        return false;
    }

    float vertices[] = {
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    m_vao.Bind();

    m_vbo.Bind();
    m_vbo.SetData(vertices, sizeof(vertices));

    m_ebo.Bind();
    m_ebo.SetData(indices, 6);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);

    m_vao.AddBuffer(m_vbo, layout);

    return true;
}

void AppLayer::OnEvent(Event::Event& event)
{
    SPDLOG_INFO("{}", event.ToString());

    Layer::OnEvent(event);
}

void AppLayer::OnUpdate(float ts)
{
}

void AppLayer::OnRender()
{
    m_Texture->ActivateSlot(0);
    m_Texture->Bind();

	m_ShaderProgram->Bind();
    m_ShaderProgram->SetUniform1i("u_Texture", m_Texture->GetActiveSlot());

    m_vao.Bind();
	glDrawElements(GL_TRIANGLES, m_ebo.Count(), GL_UNSIGNED_INT, 0);
}
