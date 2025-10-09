#include "Core/Interactor/PerspectiveCamera.h"

#include <glm/ext.hpp>

PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip)
    : m_Fov(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)
{
    
}

void PerspectiveCamera::SetPosition(const glm::vec3& position)
{
    m_Position = position;
}

glm::vec3 PerspectiveCamera::GetPosition() const
{
    return m_Position;
}

void PerspectiveCamera::AddPosition(const glm::vec3& addPosition)
{
    m_Position += addPosition;
}

void PerspectiveCamera::SetUp(const glm::vec3& up)
{
    m_Up = up;
}

glm::vec3 PerspectiveCamera::GetUp() const
{
    return m_Up;
}

void PerspectiveCamera::SetForward(const glm::vec3& forward)
{
    m_Forward = forward;
}

glm::vec3 PerspectiveCamera::GetForward() const
{
    return m_Forward;
}

glm::mat4 PerspectiveCamera::GetViewMatrix() const
{
    return glm::lookAtRH(m_Position, m_Position + m_Forward, m_Up);
}

glm::mat4 PerspectiveCamera::GetProjectionMatrix() const
{
    return glm::perspective(m_Fov, m_AspectRatio, m_NearClip, m_FarClip);
}



