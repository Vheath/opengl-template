#include "include/cube.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

bool Cube::firstCall = true;
Cube::Cube(int modelLoc, glm::vec3 scale, glm::vec3 translate)
    : RenderableObject { modelLoc, scale, translate }
{
    if (firstCall) {
        firstCall = false;

        glGenVertexArrays(1, &Cube::VAO);
        glGenBuffers(1, &Cube::VBO);
        glGenBuffers(1, &Cube::EBO);
        glBindVertexArray(Cube::VAO);

        glBindBuffer(GL_ARRAY_BUFFER, Cube::VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(mVertices), mVertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Cube::EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mIndicies), mIndicies, GL_STATIC_DRAW);
    }
};

void Cube::render()
{
    glBindVertexArray(Cube::VAO);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, mScaleVector);
    model = glm::translate(model, mTranslateVector);
    model = glm::rotate(model, mRadians, mRotationVector);
    glUniformMatrix4fv(mModelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
