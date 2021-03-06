cmake_minimum_required(VERSION 3.10)

project(SSprofiler)

add_library(SSprofiler STATIC
	source/frdProfile.cpp
	source/frdProfile.hpp
)

target_include_directories(SSprofiler INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source")

if (MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # using Clang
  target_compile_options( SSprofiler PRIVATE -march=native -O3)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /O2")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  target_compile_options( SSprofiler PRIVATE -march=native -O3)
endif()
