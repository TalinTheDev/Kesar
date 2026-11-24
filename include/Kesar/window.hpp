// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/renderer.hpp>
#include <functional>
#include <memory>
#include <string>

struct GLFWwindow;

namespace Kesar {
class Window {
public:
  Window(int width, int height, std::string title);
  ~Window();

  void run(const std::function<void()> &draw,
           const std::function<void()> &update);

  void onKey(void (*keyCallback)(Window *window, int key, int action));
  void close();
  Renderer &getRenderer();
  Renderer &getRenderer(Color c);

private:
  GLFWwindow *window;
  std::unique_ptr<Renderer> renderer;

  void (*draw)();
  void (*update)();

  void (*kCallback)(Window *window, int key, int action) = nullptr;
  static void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                          int mods);
};
} // namespace Kesar
