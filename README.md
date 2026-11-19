# Kesar

A OpenGL-based 3D game engine. Perhaps slightly opinionated.

*Note: As I build Kesar (mostly for fun and learning purposes), I am also developing a Minecraft like game on the side,
that uses Kesar (for testing purposes and for more fun). So features will be added to Kesar as the need arises.*

## Building

### Prerequisites

- A C++23 compatible compiler
- CMake 4.0+
- Ninja
- Graphics drivers supporting OpenGL 4.6+ (core)
- Git

GLFW (for window management) is automatically fetched and compiled and GLAD (for OpenGL loading) is already included in
this repository.

### Build Instructions

1. Clone this repository

```bash
git clone https://github.com/TalinTheDev/Kesar.git
cd Kesar
```

2. Configure and build:

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

By default, this produces a static library that can be linked into another CMake project (your game, for example).

## Using Kesar

Include Kesar into your CMake project using `FetchContent`

```cmake
include(FetchContent)

FetchContent_Declare(
    Kesar
    GIT_REPOSITORY https://github.com/TalinTheDev/Kesar.git
    GIT_TAG 1.0 # Replace with required version or branch name (any available Git tag really)
)

FetchContent_MakeAvailable(Kesar)

target_link_libraries(${PROJECT_NAME} PRIVATE Kesar::Kesar)
```

For local development of Kesar alongside a game that uses it (such as the game I'm developing), override the Git
dependency to use a local checkout instead of fetching Kesar from GitHub.

```bash
cmake -S . -B build -G Ninja -DFETCHCONTENT_SOURCE_DIR_KESAR="../Kesar"
```

## Project Structure
```
Kesar/
├── include/   # Public engine headers
├── src/       # Engine implementation files
├── vendor/
│   └── glad/  # OpenGL loader
```

## License
Kesar is licensed under the MIT License. See [LICENSE](LICENSE) for details.

### Third-Party Licenses
Kesar uses the following open-source libraries:

- **[GLFW](https://github.com/glfw/glfw)** — Licensed under the [zlib/libpng License](https://github.com/glfw/glfw/blob/master/LICENSE.md)
- **[GLAD 2](https://github.com/Dav1dde/glad)** — Licensed under the [MIT License](https://github.com/Dav1dde/glad/blob/glad2/LICENSE). The generated code may also incorporate Khronos specifications and headers subject to Apache 2.0 and other permissive licenses.

Third-party components remain subject to their respective licenses.
