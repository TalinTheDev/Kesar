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

private:
  GLFWwindow *window;
  void (*draw)();
  void (*update)();
};
} // namespace Kesar
