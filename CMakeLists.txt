cmake_minimum_required(VERSION 3.26)
project(HostVMSpoofer)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/**)

add_executable(HostVMSpoofer ${SOURCES})
