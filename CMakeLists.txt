cmake_minimum_required(VERSION 3.16)
project(autocore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror)

# --- Library: communication layer ---
add_library(autocore_comm
    src/comm/CanFrame.cpp
)
target_include_directories(autocore_comm PUBLIC include)

# --- Testing ---
enable_testing()
find_package(GTest REQUIRED)

add_executable(autocore_tests
    tests/unit/comm/test_can_frame.cpp
)
target_link_libraries(autocore_tests
    PRIVATE autocore_comm GTest::gtest_main GTest::gmock
)
add_test(NAME autocore_tests COMMAND autocore_tests)