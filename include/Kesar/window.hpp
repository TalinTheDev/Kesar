// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

struct GLFWwindow;

namespace Kesar {
class Window {
public:
  Window(int width, int height, std::string title);
  ~Window();

  void run(void (*draw)(), void (*update)());
  void onKey(void (*keyCallback)(int key, int action));

private:
  GLFWwindow *window;
  void (*draw)();
  void (*update)();
  inline static void (*kCallback)(int key, int action) = nullptr;

  static void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                          int mods) {
    kCallback(key, action);
  }
};
} // namespace Kesar
