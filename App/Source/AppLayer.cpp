#include "AppLayer.h"

#include <cassert>

#include <Core/Log/Log.h>

#include <Core/Common/Macro.h>
#include <Core/Application.h>
#include <Core/Renderer/VBLayout.h>
#include <Core/Renderer/ShaderProgramUtils.h>
#include <Core/Renderer/TextureUtils.h>
#include <Core/Event/MouseButtonEvent.h>
#include <Core/Event/KeyEvent.h>

using namespace Core;
using namespace Core::Renderer;
using namespace Core::Event;

bool AppLayer::Init()
{
    m_ShaderProgram = ShaderProgramUtils::CreateShaderProgramFromFile(
        SHADER_PATH(Vertex.glsl), SHADER_PATH(Fragment.glsl));
    if (!m_ShaderProgram)
    {
        LOG_CRITICAL("Failed to Create ShaderProgram");
        return false;
    }

    m_Texture = TextureUtils::CreateTexture2DFromFile(TEXTURE_PATH(Copilot.png));
    if (!m_Texture)
    {
        LOG_CRITICAL("Failed to Create Texture2D");
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

void AppLayer::OnEvent(Core::Event::Event& event)
{
    LOG_INFO("{}", event.ToString());

    if (event.Type() == EventType::KeyEvent)
    {
        auto& ev = dynamic_cast<KeyEvent&>(event);

        float step = 0.1f;
        auto scanCode = ev.Key();
        if (scanCode == GLFW_KEY_W)
        {
            origin.z -= step;
        }
        if (scanCode == GLFW_KEY_S)
        {
            origin.z += step;
        }
        if (scanCode == GLFW_KEY_A)
        {
            origin.x += step;
        }
        if (scanCode == GLFW_KEY_D)
        {
            origin.x -= step;
        }
    }
    Layer::OnEvent(event);
}

void AppLayer::OnUpdate(float ts)
{
}

void AppLayer::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT);

    m_Texture->ActivateSlot(1);
    m_Texture->Bind();

	m_ShaderProgram->Bind();
    m_ShaderProgram->SetUniform1i("u_Texture", m_Texture->GetActiveSlot());

    static auto model = glm::translate(glm::mat4{ 1.0f }, glm::vec3{0.0f, 0.0f, -5.0f});
    model = glm::rotate(model, glm::radians(2.0f), glm::vec3{ 1.0f, 0.0f, 0.0f });

    auto view = glm::lookAtRH(origin, origin + lookAt, up);

    static auto proj = glm::perspective(glm::radians(45.0f), Application::Get().Aspect(), 0.1f, 100.0f);

    m_ShaderProgram->SetUniform4mat("u_ModelMatrix", model);
    m_ShaderProgram->SetUniform4mat("u_ViewMatrix", view);
    m_ShaderProgram->SetUniform4mat("u_ProjectMatrix", proj);

    m_vao.Bind();
	glDrawElements(GL_TRIANGLES, m_ebo.Count(), GL_UNSIGNED_INT, 0);
}
