// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#pragma once

#include <Kesar/log.hpp>
#include <filesystem>
#include <format>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <map>
#include <string>

using namespace Kesar::log;

namespace Kesar {
class Shader {
public:
  Shader(const std::string &vert, const std::string &frag,
         bool external = true);
  ~Shader();

  unsigned int getProgram() const;
  void uniform(std::string name, glm::mat4 matrix);

private:
  unsigned int id;
  std::map<std::string, unsigned int> uniforms{};

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

inline std::string defaultVertexShader = R"(
#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vColor;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    vColor = aColor;

}
)";

inline std::string defaultFragmentShader = R"(
#version 460 core
out vec4 FragColor;

in vec4 vColor;

void main()
{
    FragColor = vColor;
} 
)";

} // namespace Kesar
