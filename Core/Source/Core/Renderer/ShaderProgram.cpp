

#include "Core/Renderer/ShaderProgram.h"
#include <Core/Renderer/GLCommon.h>
#include <Core/Renderer/Shader.h>

#include <spdlog/spdlog.h>

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
