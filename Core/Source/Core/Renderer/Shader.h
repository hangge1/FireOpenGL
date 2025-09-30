
#pragma once    

#include <string>

#include <Core/Renderer/GLApi.h>
#include <Core/Renderer/GLObject.h>

namespace Core::Renderer {

class Shader : public GLObject
{
public:
    Shader(const std::string& shaderSource, unsigned int shaderType = GL_VERTEX_SHADER);
    ~Shader();
    DELETE_COPY_ASSIGNMENT(Shader);

    void Bind() const override;
    void Unbind() const override;

protected:
    unsigned int m_ShaderType;
};

}