cmake_minimum_required(VERSION 3.10)
project(openglTry)
find_package(glfw3 3.3 REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(OpenGL REQUIRED)
add_subdirectory(lib/gladF)
add_subdirectory(lib/stb_image)
add_executable(
    out
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/shader.cpp
    ${PROJECT_SOURCE_DIR}/src/camera.cpp
    ${PROJECT_SOURCE_DIR}/src/renderableobj.cpp
    ${PROJECT_SOURCE_DIR}/src/cube.cpp
    ${PROJECT_SOURCE_DIR}/src/sphere.cpp
    ${PROJECT_SOURCE_DIR}/src/circle.cpp
)
target_compile_features(out PRIVATE cxx_std_20)

target_include_directories(out PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(out glad)
target_link_libraries(out stb_image)
target_link_libraries(out glfw)
target_link_libraries(out OpenGL::GL)
