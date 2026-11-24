// Copyright (c) 2026 Talin Sharma
// SPDX-License-Identifier: MIT

#include <Kesar/shader.hpp>
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Kesar;

void checkSuccess(unsigned int shader, bool link = false) {
  int success;
  char infoLog[512];

  glGetShaderiv(shader, !link ? GL_COMPILE_STATUS : GL_LINK_STATUS, &success);
  if (!success) {
    if (link)
      glGetProgramInfoLog(shader, 512, nullptr, infoLog);
    else
      glGetShaderInfoLog(shader, 512, nullptr, infoLog);

    error(std::format("[SHADER{}] {}", link ? "" : " (linking)", infoLog));
  }
}
Shader::Shader(const std::string &vert, const std::string &frag,
               bool external) {
  unsigned int vertex, fragment;
  std::string vSource, fSource;
  const char *vertSource;
  const char *fragSource;

  if (external) {
    vSource = readFile(vert);
    vertSource = vSource.c_str();

    fSource = readFile(frag);
    fragSource = fSource.c_str();
  } else {
    vertSource = vert.c_str();
    fragSource = frag.c_str();
  }

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vertSource, nullptr);
  glCompileShader(vertex);
  checkSuccess(vertex);

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fragSource, nullptr);
  glCompileShader(fragment);
  checkSuccess(fragment);

  id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);
  glLinkProgram(id);
  checkSuccess(id);

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}
Shader::~Shader() { glDeleteProgram(id); }

unsigned int Shader::getProgram() const { return id; }

void Shader::uniform(std::string name, glm::mat4 matrix) {
  unsigned int loc = 0;
  if (uniforms.contains(name)) {
    loc = uniforms[name];
  } else {
    loc = glGetUniformLocation(id, name.c_str());
    uniforms[name] = loc;
  }
  glUseProgram(id);
  glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
}
