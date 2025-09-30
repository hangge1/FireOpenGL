#pragma once

#include <Core/Common/Macro.h>
#include <Core/Renderer/GLObject.h>
#include <Core/Renderer/GLApi.h>

namespace Core::Renderer {

class VBO : public GLObject
{
public:
    VBO();
    ~VBO();
    DELETE_COPY_ASSIGNMENT(VBO);

    void Bind() const override;
    void Unbind() const override;
    void SetData(const void* data, unsigned int size, unsigned int usage = GL_STATIC_DRAW);
};

}