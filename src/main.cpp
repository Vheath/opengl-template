#include "include/camera.h"
#include "include/circle.h"
#include "include/common.h"
#include "include/cube.h"
#include "include/shader.h"
#include "include/sphere.h"
#include "lib/stb_image/stb_image.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/common.hpp>
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
        glm::vec3(0.0f, 0.0f, 4.0f),
        glm::vec3(-0.0f, -0.0f, -1.0f),
        glGetUniformLocation(ourShader.ID, "view"),
        glGetUniformLocation(ourShader.ID, "projection")
    };

    int modelLoc { glGetUniformLocation(ourShader.ID, "model") };
    // Cube cube1 { modelLoc, glm::vec3(1.5f, 1.5f, 1.5f), glm::vec3(0.0f, 0.0f, 0.0f) };
    Circle circle1 { modelLoc, -1.0f, 1 };
    circle1.setVertices(25);
    circle1.recalculate();

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

        glm::vec3 color = glm::vec3(0.5f, 0.3f, 0.2f);
        glUniform3fv(glGetUniformLocation(ourShader.ID, "uniColor"), 1, glm::value_ptr(color));

        ourCamera.process();

        circle1.render();

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
