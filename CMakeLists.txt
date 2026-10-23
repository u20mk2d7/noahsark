cmake_minimum_required(VERSION 3.20)

project(networking)

set(CMAKE_CXX_STANDARD 26)

# Find LLVM package
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Find Boost and Abseil packages provided by Conan

find_package(Boost REQUIRED)
find_package(absl REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)
find_package(jemalloc REQUIRED)
find_package(flatbuffers REQUIRED)

add_executable(
	${CMAKE_PROJECT_NAME}
	/Users/localhost/repos/training/cpp/tips/totw1.cpp
)
# Map LLVM components to link libraries
llvm_map_components_to_libnames(llvm_libs core orcjit support native)

# Link LLVM, Boost, and Abseil libraries to your target
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE 
    ${llvm_libs}
    Boost::boost
    absl::flat_hash_map
    absl::strings
)
