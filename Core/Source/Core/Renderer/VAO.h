#pragma once

#include <Core/Common/Macro.h>
#include <Core/Renderer/GLObject.h>
#include <Core/Renderer/GLApi.h>

namespace Core::Renderer {

class VBO;
class VertexBufferLayout;

class VAO : public GLObject
{
public:
    VAO();
    ~VAO();
    DELETE_COPY_ASSIGNMENT(VAO);

    void Bind() const override;
    void Unbind() const override;
    void AddBuffer(const VBO& vbo, const VertexBufferLayout& layout);
};

}