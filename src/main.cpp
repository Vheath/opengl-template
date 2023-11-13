#include "include/camera.h"
#include "include/common.h"
#include "include/cube.h"
#include "include/shader.h"
#include "lib/stb_image/stb_image.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/ext/vector_float3.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window, Camera& camera);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }
    // glEnable(GL_DEPTH_TEST);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader ourShader("../src/ShadersGLSL/shader.vert",
        "../src/ShadersGLSL/shader.frag");

    Camera ourCamera {
        glm::vec3(3.0f, 3.0f, 3.0f),
        glm::vec3(-0.5f, -0.5f, -0.5f),
        glGetUniformLocation(ourShader.ID, "view"),
        glGetUniformLocation(ourShader.ID, "projection")
    };
    int count = 10;
    int radius = 1;
    float step = 360.0 / count;

    float* vertices { new float[count * 3] {} };
    for (int i { 0 }; i < count; i += 3) {
        vertices[i + 0] = std::sin(step * i); // x
        vertices[i + 1] = std::cos(step * i); // y
        vertices[i + 2] = 0; // z
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)+0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    // render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window, ourCamera);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &Cube::VAO);
    glDeleteBuffers(1, &Cube::VBO);
    glDeleteBuffers(1, &Cube::EBO);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window, Camera& camera)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
