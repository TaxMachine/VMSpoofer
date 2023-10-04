cmake_minimum_required(VERSION 3.26)
project(HostVMSpoofer)
project(Decoy)
project(VMDiscovery)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(CMAKE_CXX_FLAGS "-mwindows -Wl,--no-undefined -static-libgcc -static ${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/**)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW CONFIG REQUIRED)

file(GLOB_RECURSE IMGUI_SOURCES
        ${SOURCE_DIR}/imgui/*.cpp
        ${SOURCE_DIR}/imgui/*.h
        ${SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
        ${SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.h
)

include_directories(${SOURCE_DIR}/imgui)

add_executable(HostVMSpoofer ${SOURCES} ${IMGUI_SOURCES})

add_executable(Decoy decoy/main.c)

add_executable(VMDiscovery VMDiscovery/main.cpp)

target_link_libraries(HostVMSpoofer PRIVATE
        opengl32
        glfw
        GLEW::GLEW
        imm32
)
