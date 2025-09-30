
#pragma once

#include <Core/Renderer/GLObject.h>

namespace Core::Renderer {

class Texture : public GLObject
{
public:
    Texture();
    virtual ~Texture();

    void ActivateSlot(unsigned int slot = 0);
    unsigned int GetActiveSlot() const { return m_Slot; };

protected:
    virtual void InitTextureParameters();
    unsigned int m_Slot {};
};

}