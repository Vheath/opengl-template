#include "include/renderableobj.h"
#include <glm/ext/vector_float3.hpp>

RenderableObject::RenderableObject(int modelLoc,
    glm::vec3 scale,
    glm::vec3 translate)
    : mModelLoc { modelLoc }
    , mScaleVector { scale }
    , mTranslateVector { translate } {};

void RenderableObject::setTranslateVec(glm::vec3 translate)
{
    mTranslateVector = translate;
}

void RenderableObject::setScaleVec(glm::vec3 scale)
{
    mScaleVector = scale;
}

void RenderableObject::setRotation(float radians, glm::vec3 rotation)
{
    if (rotation != glm::vec3(0.0f, 0.0f, 0.0f))
        mRotationVector = rotation;
    else
        mRotationVector = glm::vec3(1.0f, 1.0f, 1.0f);
    mRadians = radians;
}

glm::vec3 RenderableObject::getScaleVec()
{
    return mScaleVector;
}

glm::vec3 RenderableObject::getTranslateVec()
{
    return mTranslateVector;
}

glm::vec3 RenderableObject::getRotationVec()
{
    return mRotationVector;
}
