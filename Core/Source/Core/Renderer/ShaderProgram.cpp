

#include "Core/Renderer/ShaderProgram.h"
#include <Core/Renderer/GLApi.h>
#include <Core/Renderer/Shader.h>

#include <spdlog/spdlog.h>
#include <glm/gtc/type_ptr.hpp>

using namespace Core::Renderer;

ShaderProgram::ShaderProgram()
{
    m_ID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_ID);
}

void ShaderProgram::Bind() const
{
    glUseProgram(m_ID);
}

void ShaderProgram::Unbind() const
{
    glUseProgram(0);
}
void ShaderProgram::AttachShader(const Shader& shader)
{
    glAttachShader(m_ID, shader.ID());
}

void ShaderProgram::Link()
{
    int success = -1;
    glLinkProgram(m_ID);
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    char infoLog[512] {};
    if (!success)
    {
        glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
        SPDLOG_ERROR("ERROR::PROGRAM\n{}", infoLog);
    }
}

void ShaderProgram::SetUniform1i(const std::string& name, unsigned int v) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        __debugbreak();
    }
    glUniform1i(location, v);
}

void ShaderProgram::SetUniform1f(const std::string& name, float v) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        __debugbreak();
    }
    glUniform1f(location, v);
}

void ShaderProgram::SetUniform2f(const std::string& name, float v1, float v2) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        __debugbreak();
    }
    glUniform2f(location, v1, v2);
}

void ShaderProgram::SetUniform3f(const std::string& name, float v1, float v2, float v3) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        __debugbreak();
    }
    glUniform3f(location, v1, v2, v3);
}

void ShaderProgram::SetUniform4mat(const std::string& name, const glm::mat4& v) const
{
    int location = glGetUniformLocation(m_ID, name.c_str());
    if (location == -1)
    {
        __debugbreak();
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(v));
}
