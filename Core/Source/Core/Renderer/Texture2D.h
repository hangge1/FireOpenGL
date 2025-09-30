
#pragma once

#include <Core/Renderer/Texture.h>

namespace Core::Renderer {

class Texture2D : public Texture
{
public:
    Texture2D() = default;
    virtual ~Texture2D() = default;

    void Bind() const override;
    void Unbind() const override;
    void Init(unsigned char* data, int width, int height, int channels);

protected:
    unsigned int ChannelToFormat(int channels);
    void InitTextureParameters() override;
    
protected:
    unsigned int m_Height {};
    unsigned int m_Width  {};
    unsigned int m_Channels  {};
};

}