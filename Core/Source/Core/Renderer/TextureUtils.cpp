
#include "Core/Renderer/TextureUtils.h"

#include <spdlog/spdlog.h>
#include <stb_image.h>


using namespace Core::Renderer;

std::unique_ptr<Texture2D> TextureUtils::CreateTexture2DFromFile(const std::string& path)
{
    stbi_set_flip_vertically_on_load(TextureUtils::IsFlipY());

    int width {};
    int height {};
    int channels {};

    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if(!data)
    {
        SPDLOG_ERROR("Failed to load texture from file: {}", path);
        return nullptr;
    }

    auto result = std::make_unique<Texture2D>();
    result->Init(data, width, height, channels);
    stbi_image_free(data);
    return result;
}