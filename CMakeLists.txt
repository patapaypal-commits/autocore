cmake_minimum_required(VERSION 3.16)
project(autocore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror)

add_library(autocore_comm
    src/comm/CanFrame.cpp
)
target_include_directories(autocore_comm PUBLIC include)