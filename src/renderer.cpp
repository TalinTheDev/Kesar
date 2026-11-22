// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "Kesar/shader.hpp"
#include <Kesar/renderer.hpp>
#include <glad/gl.h>

using namespace Kesar;

Renderer::Renderer()
    : defaultShader(defaultVertexShader, defaultFragmentShader, false) {
  clearColor = Color{};
}
Renderer::Renderer(Color c)
    : defaultShader(defaultVertexShader, defaultFragmentShader, false) {
  clearColor = c;
  glClearColor(c.r, c.g, c.b, c.a);
}

void Renderer::setClearColor(Color c) {
  clearColor = c;
  glClearColor(c.r, c.g, c.b, c.a);
}

void Renderer::draw(const Mesh &m) const {
  glUseProgram(defaultShader.getProgram());
  glBindVertexArray(m.getVertexArray());

  if (m.indexCount > 0) {
    glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, nullptr);
  } else {
    glDrawArrays(GL_TRIANGLES, 0, m.vertexCount);
  }
}
