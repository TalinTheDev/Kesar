// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/window.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Kesar {
class App {
public:
  App();
  ~App();

  // Disable copying to prevent double deletes of a window owned by two Apps
  App(App &) = delete;
  App &operator=(const App &) = delete;

  void onError(void (*errCallback)(std::string description));
  Window &createWindow(int width, int height, const std::string &title);
  double getTime() const;

private:
  std::vector<std::unique_ptr<Window>> windows;
  inline static void (*eCallback)(std::string description) = nullptr;

  static void errCallback(int error, const char *description) {
    eCallback("[GLFW] " + std::string(description));
  }
};
} // namespace Kesar
