#include "include/circle.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

Circle::Circle(const int modelLoc, const float radius, const unsigned int verticesAmount,
    const glm::vec3 scale, const glm::vec3 translate)
    : RenderableObject { modelLoc, scale, translate }
    , mRadius(radius)
    , mVerticesAmount(verticesAmount)
{
    if (mVerticesAmount < 3)
        mVerticesAmount = 3;

    if (mRadius < 0)
        mRadius = -mRadius;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    float twicePi = 2.0f * glm::pi<float>();

    for (int i = 0; i <= mVerticesAmount; ++i) {
        mVertices.push_back(mRadius * std::cos(i * twicePi / mVerticesAmount));
        mVertices.push_back(mRadius * std::sin(i * twicePi / mVerticesAmount));
        mVertices.push_back(0.0f);
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);
};

float Circle::getRadius() const
{
    return mRadius;
}

unsigned int Circle::getVertices() const
{
    return mVerticesAmount;
}

void Circle::setRadius(float radius)
{
    if (radius >= 0)
        mRadius = radius;
    else
        mRadius = -radius;
}

void Circle::setVertices(unsigned int verticesAmount)
{
    if (verticesAmount >= 3)
        mVerticesAmount = verticesAmount;
    else
        mVerticesAmount = 3;
}

void Circle::recalculate()
{
    mVertices.clear();
    float twicePi = 2.0f * glm::pi<float>();

    for (int i = 0; i <= mVerticesAmount; ++i) {
        mVertices.push_back(mRadius * std::cos(i * twicePi / mVerticesAmount));
        mVertices.push_back(mRadius * std::sin(i * twicePi / mVerticesAmount));
        mVertices.push_back(0.0f);
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);
}

void Circle::renderHollow() const
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, mScaleVector);
    model = glm::translate(model, mTranslateVector);
    model = glm::rotate(model, mRadians, mRotationVector);
    glUniformMatrix4fv(mModelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glDrawArrays(GL_LINE_LOOP, 0, mVerticesAmount);
}

void Circle::render() const
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, mScaleVector);
    model = glm::translate(model, mTranslateVector);
    model = glm::rotate(model, mRadians, mRotationVector);
    glUniformMatrix4fv(mModelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLE_FAN, 0, mVerticesAmount);
}
