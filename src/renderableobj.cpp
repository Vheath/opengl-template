#include "include/renderableobj.h"
#include <glm/ext/vector_float3.hpp>

RenderableObject::RenderableObject(const int modelLoc,
    const glm::vec3 scale,
    const glm::vec3 translate)
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
    mRotationVector = rotation;
    mRadians = radians;
}

glm::vec3 RenderableObject::getScaleVec() const
{
    return mScaleVector;
}

glm::vec3 RenderableObject::getTranslateVec() const
{
    return mTranslateVector;
}

glm::vec3 RenderableObject::getRotationVec() const
{
    return mRotationVector;
}
