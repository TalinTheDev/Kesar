// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/camera.hpp>
#include <Kesar/mesh.hpp>
#include <Kesar/shader.hpp>
#include <Kesar/types.hpp>

namespace Kesar {
class Renderer {
public:
  Renderer();
  Renderer(Color c);
  ~Renderer() = default;

  void setClearColor(Color c);
  void draw(const Mesh &m);
  void setCamera(Camera &c);

private:
  Color clearColor;
  Shader defaultShader;
  Camera *camera = nullptr;
};
} // namespace Kesar
