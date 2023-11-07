#include "include/camera.h"
#include "include/common.h"
#include <glad/glad.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(glm::vec3 cameraPos, glm::vec3 cameraFront, int viewLoc, int projectionLoc)
    : mCameraPos { cameraPos }
    , mCameraFront(cameraFront)
    , mViewLoc(viewLoc)
    , mProjectionLoc(projectionLoc) {};

void Camera::setFov(float degree)
{
    mFovDegree = degree;
    glm::mat4 projection = glm::perspective(glm::radians(mFovDegree),
        static_cast<float>(SCR_WIDTH) / static_cast<float>(SCR_HEIGHT), 0.1f, 100.0f);
    glUniformMatrix4fv(mProjectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::process() const
{
    static glm::mat4 view = glm::lookAt(mCameraPos, mCameraPos + mCameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
    static glm::mat4 projection = glm::perspective(glm::radians(mFovDegree),
        static_cast<float>(SCR_WIDTH) / static_cast<float>(SCR_HEIGHT), 0.1f, 100.0f);
    glUniformMatrix4fv(mViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(mProjectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
}
