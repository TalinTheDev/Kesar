// Copyright (c) 2025 Talin Sharma
// SPDX-License-Identifier: MIT

#include "log.hpp"
#include "constants.h"
#include <iostream>
#include <string>

kesar::Log::Log() {}

kesar::Log::~Log() {}

void kesar::Log::info(std::string msg) {
  std::cout << "[INFO] " << msg << std::endl;
}
void kesar::Log::warn(std::string msg) {
  std::cout << YELLOW_F << "[WARN] " << RESET << msg << std::endl;
}
void kesar::Log::error(std::string msg) {
  std::cout << RED_F << "[ERROR] " << RESET << msg << std::endl;
}
void kesar::Log::debug(std::string msg) {
  std::cout << GREEN_F << "[DEBUG] " << RESET << msg << std::endl;
}
