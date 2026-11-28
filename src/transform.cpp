// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/transform.hpp>
#include <Kesar/types.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace Kesar;

Transform::Transform(Vector3 translate, Vector3 rotate, Vector3 scale)
    : translate(translate), rotate(rotate), scale(scale) {
  glm::quat orientation{glm::vec3(
      glm::radians(rotate.x), glm::radians(rotate.y), glm::radians(rotate.z))};
  glm::mat4 rotationMatrix = glm::toMat4(orientation);

  matrix =
      glm::translate(matrix, glm::vec3{translate.x, translate.y, translate.z}) *
      rotationMatrix *
      glm::scale(glm::mat4(1.0f), glm::vec3{scale.x, scale.y, scale.z});
}

glm::mat4 Transform::getMatrix() const { return matrix; }
