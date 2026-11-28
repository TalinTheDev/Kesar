// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/app.hpp>
#include <Kesar/log.hpp>
#include <Kesar/window.hpp>
#include <memory>
#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

using namespace Kesar;
using namespace Kesar::log;

App::App() {
  glfwSetErrorCallback(errCallback);
  if (!glfwInit()) {
    error("GLFW Initialization failed");
  }
}

App::~App() {
  // Clear windows list first to ensure they all get deleted before closing GLFW
  windows.clear();
  glfwTerminate();
  info("App destroyed");
}

void App::onError(void (*errCallback)(std::string)) { eCallback = errCallback; }

Window &App::createWindow(int width, int height, const std::string &title) {
  std::unique_ptr<Window> window =
      std::make_unique<Window>(width, height, std::move(title));
  Window &ptr = *window;
  windows.push_back(std::move(window));

  return ptr;
};

double App::deltaTime() { return glfwGetTime(); }
