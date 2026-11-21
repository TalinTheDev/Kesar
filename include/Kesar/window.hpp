// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

namespace Kesar {
class Window {
public:
  Window(int width, int height, std::string title);
  ~Window() = default;

  void run(void (*run)());
};
} // namespace Kesar
