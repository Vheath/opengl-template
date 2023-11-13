#ifndef SPHERE_H
#define SPHERE_H
#include "renderableobj.h"
#include <cmath>

class Sphere : public RenderableObject {
public:
    Sphere(int modelLoc, float radius, unsigned int verticesAmount,
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));

    void render();

private:
    static bool firstCall;
    unsigned int VAO {}, VBO {}, EBO {};
    int mModelLoc;
    float mRadius;
    unsigned int mVerticesAmount;
    float mVertices[27] {
        std::sin(0.0f), std::cos(0.0f), 0.0f,
        std::sin(45.0f), std::cos(45.0f), 0.0f,
        std::sin(90.0f), std::cos(90.0f), 0.0f,
        std::sin(135.0f), std::cos(135.0f), 0.0f,
        std::sin(180.0f), std::cos(180.0f), 0.0f,
        std::sin(225.0f), std::cos(225.0f), 0.0f,
        std::sin(270.0f), std::cos(270.0f), 0.0f,
        std::sin(315.0f), std::cos(315.0f), 0.0f,
        std::sin(360.0f), std::cos(360.0f), 0.0f
    };
    constexpr static int mIndicies[] {
        // 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0
        0,
        1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6
    };
};

#endif
