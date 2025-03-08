### CMake ###
cmake_minimum_required(VERSION 3.15...3.30)

### Compile commands generation ###
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

### Compiler settings ###
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### default C++ compile flag ###
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

### Project statement ###
project(
  Example
  VERSION 1.0
  # LANGUAGE CXX
  # DESCRIPTION "Example C++"
)

### Source path ###
set(SOURCES
  src/main.cpp
  src/graph.cpp
)

### Executable statement ###
add_executable(${PROJECT_NAME} ${SOURCES})

### Include path ###
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

### Google test fetch ###
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
  # URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

### Google test target ###
enable_testing()

add_executable(
  graph_test
  src/graph_test.cpp
  src/graph.cpp
)
target_link_libraries(
  graph_test
  GTest::gtest_main
)
target_include_directories(graph_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(graph_test)
