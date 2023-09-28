cmake_minimum_required(VERSION 3.26)
project(HostVMSpoofer)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_FLAGS "-mwindows -Wl,--no-undefined -static-libgcc ${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/**)

find_package(OpenGL REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(HostVMSpoofer ${SOURCES})

target_include_directories(HostVMSpoofer PRIVATE
        ${OPENGL_INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(HostVMSpoofer PRIVATE
        ${OPENGL_LIBRARIES}
        glfw
        imgui::imgui
)