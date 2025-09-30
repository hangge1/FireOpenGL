
#include "Core/Renderer/VBO.h"

using namespace Core::Renderer;

VBO::VBO()
{
    glGenBuffers(1, &m_ID);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &m_ID);
}

void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::SetData(const void* data, unsigned int size, unsigned int usage)
{
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}
