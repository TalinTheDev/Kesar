// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

namespace Kesar {
namespace log {
void info(std::string msg);
void warn(std::string msg);
void error(std::string msg);
void debug(std::string msg);
} // namespace log
} // namespace Kesar
