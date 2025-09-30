
#include "Core/Renderer/EBO.h"

using namespace Core::Renderer;

EBO::EBO()
{
    static_assert(sizeof(unsigned int) == sizeof(GLuint), "sizeof(unsigned int) != sizeof(GLuint)");

    glGenBuffers(1, &m_ID);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &m_ID);
}

void EBO::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void EBO::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::SetData(const void* data, unsigned int count, unsigned int usage)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usage);
    m_Count = count;
}

