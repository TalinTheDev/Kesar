// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/log.hpp>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

using namespace Kesar::log;

namespace Kesar {
class Shader {
public:
  Shader(const std::string &vert, const std::string &frag,
         bool external = true);
  ~Shader();

  unsigned int program();

private:
  unsigned int id;

  static std::string readFile(const std::string &path) {
    std::ifstream file(path, std::ios::binary);
    if (!file) {
      error(std::format("Failed to shader at {}", path));
      return "";
    }

    unsigned int size = std::filesystem::file_size(path);
    std::string content(size, '\0');

    file.read(&content[0], size);

    return content;
  };
};
} // namespace Kesar
