// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "Kesar/renderer.hpp"
#include <Kesar/log.hpp>
#include <Kesar/window.hpp>
#include <format>
#include <functional>
#include <memory>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

using namespace Kesar;
using namespace Kesar::log;

static void changeFramebufferSize(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

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

  glfwSetWindowUserPointer(window, this);
  glfwSetFramebufferSizeCallback(window, changeFramebufferSize);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  auto version = gladLoadGL(glfwGetProcAddress);
  if (!version)
    error("OpenGL Initialization failed");
  else
    info(std::format("Created window with OpenGL v{}.{}",
                     GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version)));
}

Window::~Window() {
  glfwDestroyWindow(window);
  info("Window destroyed");
}
void Window::run(const std::function<void()> &draw,
                 const std::function<void()> &update) {
  int widthFB, heightFB;
  glfwGetFramebufferSize(window, &widthFB, &heightFB);
  glViewport(0, 0, widthFB, heightFB);

  glEnable(GL_DEPTH_TEST);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    update();
    draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

void Window::onKey(void (*keyCallback)(Window *window, int, int)) {
  kCallback = keyCallback;
  glfwSetKeyCallback(window, this->keyCallback);
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
  Window *win = (Window *)glfwGetWindowUserPointer(window);
  if (win && win->kCallback)
    win->kCallback((Window *)glfwGetWindowUserPointer(window), key, action);
}

void Window::close() { glfwSetWindowShouldClose(window, GLFW_TRUE); }

Renderer &Window::getRenderer() {
  renderer = std::make_unique<Renderer>();

  return *renderer;
}

Renderer &Window::getRenderer(Color c) {
  renderer = std::make_unique<Renderer>(c);

  return *renderer;
}
