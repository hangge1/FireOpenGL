
#pragma once    

#include <string>
#include <Core/Renderer/GLCommon.h>
#include <Core/Renderer/GLObject.h>

class Shader : public GLObject
{
public:
    Shader(const std::string& shaderSource, unsigned int shaderType = GL_VERTEX_SHADER);
    ~Shader();
    DELETE_COPY_ASSIGNMENT(Shader);

    void Bind() const;
    void Unbind() const;
    
protected:
    unsigned int m_ShaderType;
};
