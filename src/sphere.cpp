#include "include/sphere.h"
#include <glad/glad.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sphere::Sphere(const int modelLoc, const float radius, const unsigned int verticesAmount,
    const glm::vec3 scale, const glm::vec3 translate)
    : RenderableObject { modelLoc, scale, translate }
    , mRadius(radius)
    , mVerticesAmount(verticesAmount)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    mIndicies = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 0 };

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mIndicies), mVertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndicies), mIndicies.data(), GL_STATIC_DRAW);
};

void Sphere::render() const
{
    glBindVertexArray(VAO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, mScaleVector);
    model = glm::translate(model, mTranslateVector);
    model = glm::rotate(model, mRadians, mRotationVector);
    glUniformMatrix4fv(mModelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glDrawElements(GL_LINES, mIndicies.size(), GL_UNSIGNED_INT, 0);
}
