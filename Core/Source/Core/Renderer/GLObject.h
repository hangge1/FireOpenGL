#pragma once

#include "Core/Common/Macro.h"

class GLObject
{
public:
    GLObject() = default;
    virtual ~GLObject() = default;
    DELETE_COPY_ASSIGNMENT(GLObject);

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

protected:
    unsigned int m_ID = 0;
};