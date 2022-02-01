cmake_minimum_required(VERSION 3.10)

project(SSprofiler)

add_library(SSprofiler INTERFACE
	source/frdProfile.hpp
)

target_include_directories(SSprofiler INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/source")
