
#pragma once    

#include <Core/Renderer/GLObject.h>


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
};

}