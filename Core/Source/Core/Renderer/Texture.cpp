
#include "Core/Renderer/Texture.h"

#include <Core/Renderer/GLApi.h>

using namespace Core::Renderer;

Texture::Texture()
{
    glGenTextures(1, &m_ID);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_ID);
}

void Core::Renderer::Texture::ActivateSlot(unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    m_Slot = slot;
}

void Texture::InitTextureParameters()
{
}