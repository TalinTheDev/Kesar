// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/types.hpp>
#include <vector>

namespace Kesar {
class Mesh {
public:
  Mesh();
  ~Mesh();

  // Disable copying
  Mesh(Mesh &) = delete;
  Mesh &operator=(const Mesh &) = delete;

  void vertices(const std::vector<Vertex> &v);
  void colors(const std::vector<Color> &c);
  void indices(const std::vector<unsigned int> &i);

private:
  int vertexCount = 0;

  unsigned int vertexData = 0;
  unsigned int colorData = 0;
  unsigned int indexData = 0;
  unsigned int attribData = 0;
};

} // namespace Kesar
