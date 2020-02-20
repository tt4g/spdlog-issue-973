cmake_minimum_required(VERSION 3.0.0)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  message("Define CMAKE_BUILD_TYPE=Debug")
  set(CMAKE_BUILD_TYPE Debug)
endif()

project(spdlog_issue_973 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(spdlog_issue_973 main.cpp)
target_include_directories(spdlog_issue_973
  PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/thirdparty/spdlog/include")
