
#pragma once

#include <string>
#include <memory>

#include <Core/Renderer/ShaderProgram.h>

std::unique_ptr<ShaderProgram> CreateShaderProgramFromSource(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

std::unique_ptr<ShaderProgram> CreateShaderProgramFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);