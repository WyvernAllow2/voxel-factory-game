cmake_minimum_required(VERSION 3.13)
project(voxel-factory-game VERSION 0.1.0 LANGUAGES C)

add_executable(${PROJECT_NAME}
    src/arena.c
    src/arena.h
    src/main.c
)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 99)
target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /permissive-
        /sdl
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -std=c99
        -Wall
        -Wextra
        -Wpedantic
        -Wsign-conversion
        -Wshadow
        -Wstrict-prototypes
        -Wundef
        -Wpointer-arith
        -Wcast-align
        -Wmissing-prototypes
    )
endif()

set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(deps/glfw)
find_package(Vulkan REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    Vulkan::Vulkan
)