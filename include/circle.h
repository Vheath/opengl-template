#ifndef CIRCLE_H
#define CIRCLE_H
#include "renderableobj.h"
#include <vector>

class Circle : public RenderableObject {
public:
    Circle(const int modelLoc, const float radius, const unsigned int verticesAmount,
        const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f),
        const glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f));

    float getRadius() const;
    unsigned int getVertices() const;
    void setRadius(const float radius);
    void setVertices(const unsigned int verticesAmount);
    void recalculate();
    void render() const;
    void renderHollow() const;

private:
    unsigned int VAO {}, VBO {};
    float mRadius;
    unsigned int mVerticesAmount;
    std::vector<float> mVertices;
};

#endif
