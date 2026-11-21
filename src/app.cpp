// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/app.hpp>
#include <Kesar/log.hpp>
#include <Kesar/window.hpp>
#include <memory>
#include <string>

using namespace Kesar;

App::App() {}

Window *App::createWindow(int width, int height, std::string title) {
  std::unique_ptr<Window> window =
      std::make_unique<Window>(width, height, std::move(title));
  Window *ptr = window.get();
  windows.push_back(std::move(window));

  return ptr;
}
