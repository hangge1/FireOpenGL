#pragma once

#include "Core/Interactor/AbstractCamera.h"

#include <glm/glm.hpp>

class PerspectiveCamera : public AbstractCamera
{
public:
    PerspectiveCamera(){}
    PerspectiveCamera(float fov, float aspectRatio, float nearClip, float farClip);
    
    void SetPosition(const glm::vec3& position);
    glm::vec3 GetPosition() const;
    void AddPosition(const glm::vec3& addPosition);

    void SetUp(const glm::vec3& up);
    glm::vec3 GetUp() const;

    void SetForward(const glm::vec3& forward);
    glm::vec3 GetForward() const;

    virtual ~PerspectiveCamera() = default;

    virtual glm::mat4 GetViewMatrix() const;
    virtual glm::mat4 GetProjectionMatrix() const;

protected:
    float m_Fov { glm::radians(45.0f) };
    float m_AspectRatio { 1.0f };
    float m_NearClip { 0.1f };
    float m_FarClip { 10.0f };

    glm::vec3 m_Position { 0.0f, 0.0f, 0.0f };
    glm::vec3 m_Up { 0.0f, 1.0f, 0.0f };
    glm::vec3 m_Forward { 0.0f, 0.0f, -1.0f };
};