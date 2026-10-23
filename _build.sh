#!/usr/bin/env bash
set -euo pipefail

echo "=== 2. Cleaning build directory ==="
rm -rf build

echo "=== 1. Formatting source ==="
find ./ -type f \( \
    -name "*.cpp" -o \
    -name "*.h"   -o \
    -name "*.c"   -o \
    -name "*.hpp" -o \
    -name "*.cxx" -o \
    -name "*.cc" \
\) -exec clang-format -i --style=LLVM {} +

echo "=== 3. Installing Conan dependencies ==="
conan install . --build=missing

echo "=== 5. Configuring CMake ==="
cmake --preset conan-release

echo "=== 7. Compiling ==="
cmake --build --preset conan-release

./build/Release/networking
