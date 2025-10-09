#pragma once

#include <glm/glm.hpp>

class AbstractCamera
{
public:
    virtual ~AbstractCamera() = default;

    virtual glm::mat4 GetViewMatrix() const = 0;
    virtual glm::mat4 GetProjectionMatrix() const = 0;
    virtual glm::mat4 GetViewProjectionMatrix() const;
};