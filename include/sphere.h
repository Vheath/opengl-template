#ifndef SPHERE_H
#define SPHERE_H
#include "renderableobj.h"

class Sphere : public RenderableObject {
public:
    Sphere(int modelLoc, float radius, unsigned int verticesAmount,
        glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));

    void render();

private:
    static bool firstCall;
    unsigned int VAO {}, VBO {};
    int mModelLoc;
    float mRadius;
    unsigned int mVerticesAmount;
    float* vertices[];
};

#endif
