// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/renderer.hpp>
#include <functional>
#include <memory>
#include <string>

struct GLFWwindow;

namespace Kesar {
class App;

class Window {
public:
  Window(int width, int height, std::string title, Kesar::App &app);
  ~Window();

  void run(const std::function<void()> &draw,
           const std::function<void()> &update);

  void onKey(void (*keyCallback)(Window *window, int key, int action));
  void onMouse(void (*mouseCallback)(Window *window, float xOffset,
                                     float yOffset));

  void close();
  Renderer &getRenderer();
  Renderer &getRenderer(Color c);

  float getDeltaTime() const;

private:
  GLFWwindow *window;
  Kesar::App &app;
  std::unique_ptr<Renderer> renderer;

  double lastFrame = 0;
  float deltaTime = 0.0f;

  void (*draw)();
  void (*update)();

  void (*kCallback)(Window *window, int key, int action) = nullptr;
  void (*mCallback)(Window *window, float xOffset, float yOffset) = nullptr;
  static void keyCallback(GLFWwindow *window, int key, int scancode, int action,
                          int mods);
  static void mouseCallback(GLFWwindow *window, double xOffset, double yOffset);
};
} // namespace Kesar
