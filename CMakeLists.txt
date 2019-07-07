cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

add_library(SSprofiller 
	source/frdProfile.cpp
)

target_include_directories(SSprofiller INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/source)