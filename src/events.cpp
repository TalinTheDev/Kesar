// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/events.hpp>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace Kesar {
namespace keys {
const int escape = GLFW_KEY_ESCAPE;
const int w = GLFW_KEY_W;
const int s = GLFW_KEY_S;
const int a = GLFW_KEY_A;
const int d = GLFW_KEY_D;
} // namespace keys
namespace actions {
const int press = GLFW_PRESS;
const int release = GLFW_RELEASE;
const int repeat = GLFW_REPEAT;
} // namespace actions
} // namespace Kesar
