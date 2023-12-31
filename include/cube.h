#ifndef CUBE_H
#define CUBE_H
#include "include/renderableobj.h"
class Cube : public RenderableObject {
public:
    Cube(int modelLoc, glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));
    void render();
    inline static unsigned int VAO, VBO, EBO;

private:
    static bool firstCall;

    constexpr static float vertices[] = {
        -0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f
    };
    constexpr static unsigned int indicies[] = {
        0, 3, 2, // Front
        2, 1, 0,
        1, 5, 6, // Right
        6, 2, 1,
        5, 4, 7, // Left
        7, 6, 5,
        4, 7, 3, // Back
        3, 0, 4,
        4, 5, 1, // Top
        1, 0, 4,
        3, 2, 6, // Bottom
        6, 7, 3
    };
};
#endif // !
