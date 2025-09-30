
#include "Core/Renderer/ShaderProgramUtils.h"

#include <optional>


#include <Core/Renderer/ShaderProgram.h>
#include <Core/Renderer/Shader.h>
#include <Core/Common/FileUtils.h>

using namespace Core::Renderer;

std::unique_ptr<ShaderProgram> ShaderProgramUtils::CreateShaderProgramFromSource(const std::string& vertexShaderSource, 
    const std::string& fragmentShaderSource)
{
    Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
    Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    auto shaderProgram = std::make_unique<ShaderProgram>();
    shaderProgram->AttachShader(vertexShader);
    shaderProgram->AttachShader(fragmentShader);
    shaderProgram->Link();
    return shaderProgram;
}

std::unique_ptr<ShaderProgram> ShaderProgramUtils::CreateShaderProgramFromFile(const std::string& vertexShaderFile, 
    const std::string& fragmentShaderFile)
{
    std::optional<std::string> vertexShaderSource = Core::Common::FileUtils::ReadFile(vertexShaderFile);
    std::optional<std::string> fragmentShaderSource = Core::Common::FileUtils::ReadFile(fragmentShaderFile);
    if (!vertexShaderSource || !fragmentShaderSource)
    {
        return nullptr;
    }
    return CreateShaderProgramFromSource(*vertexShaderSource, *fragmentShaderSource);
}
