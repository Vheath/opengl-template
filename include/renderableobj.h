#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H
#include <glm/ext/vector_float3.hpp>

class RenderableObject {
public:
    RenderableObject(int modelLoc,
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));

    glm::vec3 getScaleVec();
    glm::vec3 getTranslateVec();
    glm::vec3 getRotationVec();
    void setScaleVec(glm::vec3 scale);
    void setTranslateVec(glm::vec3 translate);
    void setRotation(float radians, glm::vec3 rotationVec);
    virtual void render() = 0;

protected:
    int mModelLoc;
    float mRadians {};
    glm::vec3 mScaleVector {};
    glm::vec3 mTranslateVector {};
    glm::vec3 mRotationVector { glm::vec3(1.0f, 1.0f, 1.0f) };
};

#endif // !RENDERABLEOBJECT_H
//
