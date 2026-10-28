#!/usr/bin/env bash
set -euo pipefail

echo "=== 2. Cleaning build directory ==="
rm -rf build

echo "=== 1. Formatting source ==="
find ./cpp -type f \( \
    -name "*.cpp" -o \
    -name "*.h"   -o \
    -name "*.c"   -o \
    -name "*.hpp" -o \
    -name "*.cxx" -o \
    -name "*.cc" \
\) -exec clang-format -i --style=LLVM {} +

find ./dsa -type f \( \
    -name "*.cpp" -o \
    -name "*.h"   -o \
    -name "*.c"   -o \
    -name "*.hpp" -o \
    -name "*.cxx" -o \
    -name "*.cc" \
\) -exec clang-format -i --style=LLVM {} +

echo "=== Installing Conan dependencies library ==="
conan install . --build=missing --profile=release

echo "=== Configuring CMake ==="
cmake --preset conan-release

echo "=== Compiling ==="
cmake --build --preset conan-release

./build/Release/networking
