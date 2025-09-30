
#pragma once    

#include <string>

#include <Core/Renderer/GLObject.h>
#include <glm/glm.hpp>

namespace Core::Renderer {

class Shader;

class ShaderProgram : public GLObject
{
public:
    ShaderProgram();
    ~ShaderProgram();
    DELETE_COPY_ASSIGNMENT(ShaderProgram);

    void Bind() const override;
    void Unbind() const override;
    void AttachShader(const Shader& shader);
    void Link();

    void SetUniform1i(const std::string& name, unsigned int v) const;
    void SetUniform1f(const std::string& name, float v) const;
    void SetUniform2f(const std::string& name, float v1, float v2) const;
    void SetUniform3f(const std::string& name, float v1, float v2, float v3) const;
    void SetUniform4mat(const std::string& name, const glm::mat4& v) const;
};

}