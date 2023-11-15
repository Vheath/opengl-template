#ifndef SPHERE_H
#define SPHERE_H
#include "renderableobj.h"
#include <vector>

class Sphere : public RenderableObject {
public:
    Sphere(const int modelLoc, const float radius,
        const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        const glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));
    void render() const;

private:
    unsigned int VAO {}, VBO {}, EBO {};
    float mRadius;
    std::vector<float> mVertices;
    std::vector<unsigned int> mIndicies;
};

#endif
