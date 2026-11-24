// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include "glm/trigonometric.hpp"
#include <Kesar/camera.hpp>
#include <Kesar/log.hpp>
#include <format>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Kesar;
using namespace Kesar::log;

Camera::Camera() {};
Camera::~Camera() {};

void Camera::perspective(float fov, float aspectRatio, float near, float far) {
  projectionMat = glm::perspective(glm::radians(fov), aspectRatio, near, far);
}

void Camera::setPosition(Vector3 pos) {
  position = glm::vec3(pos.x, pos.y, pos.z);
}
void Camera::setRotation(Vector3 rot) {
  useTarget = false;
  rotation = rot;
}
void Camera::setTarget(Vector3 pos) {
  useTarget = true;
  target = glm::vec3(pos.x, pos.y, pos.z);
}

glm::mat4 Camera::getProjection() const { return projectionMat; }
glm::mat4 Camera::getView() {
  if (useTarget) {
    if (position != target) {
      forward = glm::normalize(target - position);
    } else {
      error(std::format(
          "Camera position ({}, {}, {}) is equal to its target ({}, {}, {})",
          position.x, position.y, position.z, target.x, target.y, target.z));
    }
  } else {
    forward = {cos(glm::radians(-rotation.y)) * cos(glm::radians(rotation.x)),
               sin(glm::radians(rotation.x)),
               sin(glm::radians(-rotation.y)) * cos(glm::radians(rotation.x))};
  }
  right = glm::normalize(glm::cross(forward, {0.0f, 1.0f, 0.0f}));
  up = glm::cross(right, forward);

  viewMat = glm::lookAt(position, useTarget ? target : position + forward, up);
  return viewMat;
}
