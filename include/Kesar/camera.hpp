// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include "Kesar/types.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Kesar {
class Camera {
public:
  Camera();
  ~Camera();

  void perspective(float fov, float aspectRatio, float near, float far);
  void setPosition(Vector3 pos);
  void setRotation(Vector3 rot);
  void setTarget(Vector3 pos);

  glm::mat4 getProjection() const;
  glm::mat4 getView();

private:
  bool useTarget = false;

  glm::vec3 position{0.0f};
  Vector3 rotation{0.0f, 90.0f, 0.0f};
  glm::vec3 target{0.0f};

  glm::vec3 up{0.0f, 1.0f, 0.0f};
  glm::vec3 forward{0.0f};
  glm::vec3 right{0.0f};

  glm::mat4 projectionMat{1.0f};
  glm::mat4 viewMat{1.0f};
};
} // namespace Kesar
