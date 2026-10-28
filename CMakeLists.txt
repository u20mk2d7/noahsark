cmake_minimum_required(VERSION 3.20)

project(networking)

set(CMAKE_CXX_STANDARD 26)

# Find LLVM package
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Find Boost and Abseil packages provided by Conan

find_package(Boost)
find_package(jemalloc)
find_package(OpenSSL)
find_package(flatbuffers)
find_package(absl)
find_package(GTest)
find_package(benchmark)

add_executable(
	${CMAKE_PROJECT_NAME}
	cpp/tips/totw1.cpp
)
# Map LLVM components to link libraries
llvm_map_components_to_libnames(llvm_libs core orcjit support native)

# Link LLVM, Boost, and Abseil libraries to your target
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${llvm_libs}
    Boost::boost
    absl::flat_hash_map
    absl::strings
    boost::boost jemalloc::jemalloc openssl::openssl flatbuffers::flatbuffers abseil::abseil gtest::gtest benchmark::benchmark_main

)
