
#pragma once

#include <string>
#include <memory>

#include <Core/Renderer/ShaderProgram.h>

namespace Core::Renderer {

class ShaderProgramUtils
{
public:
    static std::unique_ptr<ShaderProgram> CreateShaderProgramFromSource(const std::string& vertexShaderSource,
        const std::string& fragmentShaderSource);

    static std::unique_ptr<ShaderProgram> CreateShaderProgramFromFile(const std::string& vertexShaderFile,
        const std::string& fragmentShaderFile);
};

}