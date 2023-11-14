#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H
#include <glm/ext/vector_float3.hpp>

class RenderableObject {
public:
    RenderableObject(const int modelLoc,
        const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        const glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));

    glm::vec3 getScaleVec() const;
    glm::vec3 getTranslateVec() const;
    glm::vec3 getRotationVec() const;
    void setScaleVec(glm::vec3 scale);
    void setTranslateVec(glm::vec3 translate);
    void setRotation(float radians, glm::vec3 rotationVec);
    virtual void render() const = 0;

protected:
    const int mModelLoc;
    float mRadians { 0.0f };
    glm::vec3 mScaleVector {};
    glm::vec3 mTranslateVector {};
    glm::vec3 mRotationVector { glm::vec3(1.0f, 1.0f, 1.0f) };
};

#endif // !RENDERABLEOBJECT_H
//
