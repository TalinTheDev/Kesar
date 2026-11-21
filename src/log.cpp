// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/constants.h>
#include <Kesar/log.hpp>
#include <iostream>
#include <string>

using namespace Kesar::log;

void info(std::string msg) { std::cout << "[INFO] " << msg << std::endl; }
void warn(std::string msg) {
  std::cout << YELLOW_F << "[WARN] " << RESET << msg << std::endl;
}
void error(std::string msg) {
  std::cout << RED_F << "[ERROR] " << RESET << msg << std::endl;
}
void debug(std::string msg) {
  std::cout << GREEN_F << "[DEBUG] " << RESET << msg << std::endl;
}
