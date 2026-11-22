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

void Renderer::draw(const Mesh &m) {
  glBindVertexArray(m.getVertexArray());

  if (m.indexCount > 0) {
    glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, nullptr);
  } else {
    glDrawArrays(GL_TRIANGLES, 0, m.vertexCount);
  }
}
