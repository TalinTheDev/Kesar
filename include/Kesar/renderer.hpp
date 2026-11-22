// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

namespace Kesar {
struct Color {
  float r = 0.0f;
  float g = 0.0f;
  float b = 0.0f;
  float a = 1.0f;
};

class Renderer {
public:
  Renderer();
  Renderer(Color c);
  ~Renderer() = default;

  void setClearColor(Color c);

private:
  Color clearColor;
};
} // namespace Kesar
