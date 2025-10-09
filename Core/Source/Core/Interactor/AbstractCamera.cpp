#include "Core/Interactor/AbstractCamera.h"


glm::mat4 AbstractCamera::GetViewProjectionMatrix() const
{
    return GetViewMatrix() * GetProjectionMatrix();
}