#include "include/sphere.h"
#include "glad/glad.h"
#include "include/renderableobj.h"

#include <GLFW/glfw3.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <iostream>

 Sphere::Sphere(const int modelLoc, const float radius, const glm::vec3 scale, const glm::vec3 translate)
     : RenderableObject { modelLoc, scale, translate }
     , mRadius { radius }
{
     glGenVertexArrays(1, &VAO);
     glGenBuffers(1, &VBO);
     glBindVertexArray(VAO);

     glBindBuffer(GL_ARRAY_BUFFER, VBO);
     glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(float), mVertices.data(), GL_STATIC_DRAW);
 }



void Sphere::render() const
{
    std::cout << "Bebra";
}
