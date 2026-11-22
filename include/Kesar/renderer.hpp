// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/mesh.hpp>
#include <Kesar/types.hpp>

namespace Kesar {
class Renderer {
public:
  Renderer();
  Renderer(Color c);
  ~Renderer() = default;

  void setClearColor(Color c);
  void draw(const Mesh &m);

private:
  Color clearColor;
};
} // namespace Kesar
