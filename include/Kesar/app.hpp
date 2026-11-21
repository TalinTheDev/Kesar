// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include "Kesar/window.hpp"
#include <memory>
#include <string>
#include <vector>

namespace Kesar {
class App {
public:
  App();
  ~App() = default;

  // Disable copying to prevent double deletes of a window owned by two Apps
  App(App &) = delete;
  App &operator=(const App &) = delete;

  Window *createWindow(int width, int height, std::string title);

private:
  std::vector<std::unique_ptr<Window>> windows;
};
} // namespace Kesar
