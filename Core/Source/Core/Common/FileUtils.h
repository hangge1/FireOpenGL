
#pragma once

#include <string>
#include <optional>

namespace Core::Common {

class FileUtils
{
public:
    static std::optional<std::string> ReadFile(const std::string& filePath);
};

}