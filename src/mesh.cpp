// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/log.hpp>
#include <Kesar/mesh.hpp>
#include <Kesar/types.hpp>
#include <format>
#include <glad/gl.h>
#include <vector>

using namespace Kesar;
using namespace Kesar::log;

Mesh::Mesh() { glCreateVertexArrays(1, &attribData); };
Mesh::~Mesh() {
  glDeleteBuffers(1, &vertexData);
  glDeleteBuffers(1, &colorData);
  glDeleteBuffers(1, &indexData);
  glDeleteVertexArrays(1, &attribData);
};

void Mesh::vertices(const std::vector<Vertex> &v) {
  if (!v.empty()) {
    if (vertexCount != 0 && vertexCount != v.size()) {
      error("Can't change the number of vertices in a mesh directly. Use "
            "Kesar::Mesh::update() for that");
      return;
    }
    if (vertexCount == 0) {
      glCreateBuffers(1, &vertexData);
    }

    vertexCount = v.size();

    glNamedBufferData(vertexData, sizeof(Vertex) * vertexCount, v.data(),
                      GL_STATIC_DRAW);

    glVertexArrayVertexBuffer(attribData, 0, vertexData, 0, sizeof(Vertex));
    glVertexArrayAttribFormat(attribData, 0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(attribData, 0, 0);
    glEnableVertexArrayAttrib(attribData, 0);
  } else {
    warn("Attempted to assign zero vertices to a mesh");
  }
}

void Mesh::colors(const std::vector<Color> &c) {
  if (vertexData == 0) {
    error("Can't assign colors to a mesh with no vertices");
    return;
  }

  unsigned int cSize = c.size();
  if (cSize != vertexCount) {
    error(std::format("Can't assign {} colors to a mesh with {} vertices",
                      cSize, vertexCount));
    return;
  }

  if (colorData == 0) {
    glCreateBuffers(1, &colorData);
  }

  glNamedBufferData(colorData, sizeof(Color) * cSize, c.data(), GL_STATIC_DRAW);

  glVertexArrayVertexBuffer(attribData, 1, colorData, 0, sizeof(Color));
  glVertexArrayAttribFormat(attribData, 1, 4, GL_FLOAT, GL_FALSE, 0);
  glVertexArrayAttribBinding(attribData, 1, 1);
  glEnableVertexArrayAttrib(attribData, 1);
}

void Mesh::indices(const std::vector<unsigned int> &i) {
  if (vertexData == 0) {
    error("Can't assign indices to a mesh with no vertices");
    return;
  }

  if (!i.empty()) {
    for (unsigned int index : i) {
      if (index >= vertexCount) {
        error("Index in mesh of bounds");
        return;
      }
    }
    indexCount = i.size();

    if (indexData == 0) {
      glCreateBuffers(1, &indexData);
    }

    glNamedBufferData(indexData, sizeof(unsigned int) * i.size(), i.data(),
                      GL_STATIC_DRAW);

    glVertexArrayElementBuffer(attribData, indexData);
  } else {
    warn("Attempted to assign zero indices to a mesh");
  }
}

unsigned int Mesh::getVertexArray() const { return attribData; }
