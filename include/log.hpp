// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

namespace kesar {
class Log {
public:
  Log();
  ~Log();

  void info(std::string msg);
  void warn(std::string msg);
  void error(std::string msg);
  void debug(std::string msg);
};
} // namespace kesar
