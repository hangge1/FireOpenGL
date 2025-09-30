
#include "Core/Renderer/Shader.h"

#include <spdlog/spdlog.h>

Shader::Shader(const std::string& shaderSource, unsigned int shaderType)
    : m_ShaderType(shaderType)
{
    m_ID = glCreateShader(shaderType);

    const char* source = shaderSource.c_str();
    glShaderSource(m_ID, 1, &source, nullptr);
    glCompileShader(m_ID);

    int success;
    glGetShaderiv(m_ID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(m_ID, 512, nullptr, infoLog);
        SPDLOG_ERROR("ERROR::SHADER::COMPILATION_FAILED\n{}", infoLog);
    }
}

Shader::~Shader()
{
    glDeleteShader(m_ID);
}

void Shader::Bind() const
{
    glUseProgram(m_ID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}
