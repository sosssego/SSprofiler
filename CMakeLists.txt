cmake_minimum_required(VERSION 3.10)

add_library(SSprofiller 
	source/frdProfile.cpp
)

target_include_directories(SSprofiller INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/source)