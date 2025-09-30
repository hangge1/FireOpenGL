
#include "Core/Common/FileUtils.h"

#include <fstream>
#include <spdlog/spdlog.h>

using namespace Core::Common;

std::optional<std::string> FileUtils::ReadFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        SPDLOG_ERROR("Error: Could not open file {}", filePath);
        return std::nullopt;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}
