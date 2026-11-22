cmake_minimum_required(VERSION 4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

project(Kesar LANGUAGES C CXX)

add_library(${PROJECT_NAME} STATIC
    src/kesar.cpp
    src/log.cpp
    src/app.cpp
    src/window.cpp
    src/events.cpp
    src/renderer.cpp
    src/mesh.cpp
    src/shader.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include
)

# Include GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.5.1
)

FetchContent_MakeAvailable(glfw)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glfw
)

# Include GLAD
target_sources(${PROJECT_NAME} PRIVATE vendor/glad/src/gl.c)


add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
