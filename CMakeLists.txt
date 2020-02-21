cmake_minimum_required(VERSION 3.0.0)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  message("Define CMAKE_BUILD_TYPE=Debug")
  set(CMAKE_BUILD_TYPE Debug)
endif()

project(spdlog_issue_973 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SPDLOG_BUILD_SHARED OFF)
set(SPDLOG_BUILD_EXAMPLE OFF)
set(SPDLOG_BUILD_EXAMPLE_HO OFF)
set(SPDLOG_BUILD_TESTS OFF)
set(SPDLOG_BUILD_TESTS_HO OFF)
set(SPDLOG_BUILD_BENCH OFF)
set(SPDLOG_SANITIZE_ADDRESS OFF)
set(SPDLOG_INSTALL OFF)
set(SPDLOG_FMT_EXTERNAL OFF)
set(SPDLOG_FMT_EXTERNAL_HO OFF)
set(SPDLOG_NO_EXCEPTIONS OFF)
add_subdirectory(thirdparty/spdlog)

add_library(spdlog_issue_973_shared_lib SHARED
  spdlog_issue_973/thread_holder.cpp
  spdlog_issue_973/thread_holder_internal.cpp)
target_include_directories(spdlog_issue_973_shared_lib
  PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/spdlog_issue_973")
target_compile_definitions(spdlog_issue_973_shared_lib
  PRIVATE
    SPDLOG_ISSUE_973_BUILD_SHARED)
target_link_libraries(spdlog_issue_973_shared_lib
  PUBLIC
    spdlog)

add_executable(spdlog_issue_973 main.cpp)
target_link_libraries(spdlog_issue_973
  PUBLIC
    spdlog_issue_973_shared_lib)

add_custom_command(TARGET spdlog_issue_973 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:spdlog_issue_973_shared_lib> $<TARGET_FILE_DIR:spdlog_issue_973>
  VERBATIM
  COMMAND_EXPAND_LISTS)
