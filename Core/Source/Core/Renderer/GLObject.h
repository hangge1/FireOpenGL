#pragma once

#include "Core/Common/Macro.h"

namespace Core::Renderer {

class GLObject
{
public:
    GLObject() = default;
    virtual ~GLObject() = default;
    DELETE_COPY_ASSIGNMENT(GLObject);

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    bool IsValid() const
    {
        return m_ID != 0;
    }

    operator bool() const
    {
        return IsValid();
    }

    unsigned int ID() const
    {
        return m_ID;
    }
protected:
    unsigned int m_ID = 0;
};

}