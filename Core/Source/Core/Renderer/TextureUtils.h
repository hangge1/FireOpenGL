
#pragma once

#include <memory>
#include <string>

#include <Core/Renderer/Texture2D.h>

class TextureUtils
{
public:
    static bool IsFlipY() { return true; }

    static std::unique_ptr<Core::Renderer::Texture2D> CreateTexture2DFromFile(const std::string& path);
};