#ifndef CAMERA_H
#define CAMERA_H

#include <glm/ext/vector_float3.hpp>
class Camera {
public:
    Camera(glm::vec3 cameraPos, glm::vec3 cameraFront, int viewLoc, int projectionLoc);
    void process() const;
    void setFov(float degree);

private:
    glm::vec3 mCameraPos;
    glm::vec3 mCameraFront;
    float mFovDegree { 45.0f };
    int mViewLoc;
    int mProjectionLoc;
};

#endif // !
