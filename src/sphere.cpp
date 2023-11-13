#include "include/sphere.h"
#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Sphere::Sphere(int modelLoc, float radius, unsigned int verticesAmount, glm::vec3 scale, glm::vec3 translate)
    : RenderableObject { modelLoc, scale, translate }
    , mModelLoc(modelLoc)
    , mRadius(radius)
    , mVerticesAmount(verticesAmount)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    float step = 360.0 / mVerticesAmount;

    float* vertices { new float[mVerticesAmount * 3] {} };
    for (int i { 0 }; i < mVerticesAmount; i += 3) {
        vertices[i + 0] = std::sin(step * i); // x
        vertices[i + 1] = std::cos(step * i); // y
        vertices[i + 2] = 0; // z
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
};
