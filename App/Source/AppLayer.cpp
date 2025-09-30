#include "AppLayer.h"

#include "Core/Application.h"

#include <glm/glm.hpp>
#include <cassert>
#include <spdlog/spdlog.h>

#include <Core/Renderer/VBLayout.h>
#include <Core/Renderer/ShaderProgramHelper.h>

using namespace Core;

static GLuint CompileShader(unsigned int type, const std::string& source)
{
	GLuint shader = glCreateShader(type);
	const char* src = source.c_str();

	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	//Error handing
	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(shader, length, &length, message);

		std::string desc = (type == GL_VERTEX_SHADER) ? "vertex shader" : "framgent shader";
		SPDLOG_ERROR("Failed to compile {}", desc);
		SPDLOG_ERROR("Error info:  {}", message);

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

static GLuint CreateShader(const std::string& vshader, const std::string& fshader)
{
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vshader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fshader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

AppLayer::AppLayer()
{
	// Create shaders
	m_ShaderProgram = CreateShaderProgramFromSource(vertexShaderSource, fragmentShaderSource);
	if (!m_ShaderProgram)
	{
		SPDLOG_CRITICAL("Failed to Create ShaderProgram");
		assert(false);
	}

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
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

    m_vao.AddBuffer(m_vbo, layout);
}

AppLayer::~AppLayer()
{

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
	m_ShaderProgram->Bind();

	// Render
    m_vao.Bind();
	glDrawElements(GL_TRIANGLES, m_ebo.Count(), GL_UNSIGNED_INT, 0);
}
