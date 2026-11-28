// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/types.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Kesar {
class Transform {
public:
  Transform(Vector3 translate = {0.0f, 0.0f, 0.0f},
            Vector3 rotate = {0.0f, 0.0f, 0.0f},
            Vector3 scale = {1.0f, 1.0f, 1.0f});
  ~Transform() = default;

  glm::mat4 getMatrix() const;

private:
  glm::mat4 matrix{1.0f};
  Vector3 translate;
  Vector3 rotate;
  Vector3 scale;
};
} // namespace Kesar
