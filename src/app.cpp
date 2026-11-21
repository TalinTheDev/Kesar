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
  if (!glfwInit()) {
    error("GLFW Initialization failed");
  }
}

App::~App() {
  // Clear windows list first to ensure they all get deleted before closing GLFW
  windows.clear();
  glfwTerminate();
}

Window *App::createWindow(int width, int height, std::string title) {
  std::unique_ptr<Window> window =
      std::make_unique<Window>(width, height, std::move(title));
  Window *ptr = window.get();
  windows.push_back(std::move(window));

  return ptr;
}
