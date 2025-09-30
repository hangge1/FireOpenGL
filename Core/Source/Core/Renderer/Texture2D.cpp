
#include "Core/Renderer/Texture2D.h"

#include <cassert>

#include <Core/Renderer/GLApi.h>

using namespace Core::Renderer;

void Texture2D::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture2D::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Init(unsigned char* data, int width, int height, int channels)
{
    assert(data);
    assert(width > 0);
    assert(height > 0);
    assert(channels > 0);
    
    m_Width = width;
    m_Height = height;
    m_Channels = channels;

    Bind();
    
    InitTextureParameters();
    
    if(data)
    {
        auto format = ChannelToFormat(channels);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
}

unsigned int Texture2D::ChannelToFormat(int channels)
{
    switch(channels)
    {
        case 1: return GL_RED;
        case 2: return GL_RG;
        case 3: return GL_RGB;
        case 4: return GL_RGBA;
        default: return GL_RGB;
    }
}

void Texture2D::InitTextureParameters()
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}