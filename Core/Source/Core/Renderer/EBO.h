#pragma once

#include <Core/Common/Macro.h>
#include <Core/Renderer/GLObject.h>
#include <Core/Renderer/GLCommon.h>


class EBO : public GLObject
{
public:
    EBO();
    ~EBO();
    DELETE_COPY_ASSIGNMENT(EBO);

    void Bind() const override;
    void Unbind() const override;
    void SetData(const void* data, unsigned int count, unsigned int usage = GL_STATIC_DRAW);
    inline unsigned int Count() const { return m_Count; };

protected:
    unsigned int m_Count = 0;
};