// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

namespace Kesar {
struct Vector3 {
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
};

typedef Vector3 Vertex;

struct Color {
  float r = 0.0f;
  float g = 0.0f;
  float b = 0.0f;
  float a = 1.0f;
};
} // namespace Kesar
