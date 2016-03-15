#cmake_minimum_required(VERSION 3.3)
project(ring_buffer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")

set(SOURCE_FILES ring_buffer.c ring_buffer.h ring_buffer_test.c)
add_executable(ring_buffer_test ${SOURCE_FILES})