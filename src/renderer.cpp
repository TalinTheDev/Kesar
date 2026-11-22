// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/renderer.hpp>
#include <glad/gl.h>

using namespace Kesar;

Renderer::Renderer() { clearColor = Color{}; }
Renderer::Renderer(Color c) {
  clearColor = c;
  glClearColor(c.r, c.g, c.b, c.a);
}

void Renderer::setClearColor(Color c) {
  clearColor = c;
  glClearColor(c.r, c.g, c.b, c.a);
}
