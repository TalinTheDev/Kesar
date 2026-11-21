// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/log.hpp>
#include <Kesar/window.hpp>
#include <format>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

using namespace Kesar;
using namespace Kesar::log;

Window::Window(int width, int height, std::string title) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (!window) {
    error("Window creation failed");
  }
  this->window = window;

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  auto version = gladLoadGL(glfwGetProcAddress);
  if (!version) {
    error("OpenGL Initialization failed");
  }

  info(std::format("Loaded OpenGL v{}.{}", GLAD_VERSION_MAJOR(version),
                   GLAD_VERSION_MINOR(version)));
}

Window::~Window() {
  glfwDestroyWindow(window);
  info("Window destroyed");
}

void Window::run(void (*draw)(), void (*update)()) {
  this->draw = draw;
  this->update = update;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    update();
    draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}
