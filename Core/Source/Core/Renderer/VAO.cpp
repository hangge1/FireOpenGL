
#include "Core/Renderer/VAO.h"

#include <Core/Renderer/VBO.h>
#include <Core/Renderer/VBLayout.h>

using namespace Core::Renderer;

VAO::VAO()
{
    glGenVertexArrays(1, &m_ID);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_ID);
}

void VAO::Bind() const
{
    glBindVertexArray(m_ID);
}

void VAO::Unbind() const
{
    glBindVertexArray(0);
}

void VAO::AddBuffer(const VBO& vbo, const VertexBufferLayout& layout)
{
    Bind();
    vbo.Bind();
    const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];

		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)(unsigned long long)offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}
