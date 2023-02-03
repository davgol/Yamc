cmake_minimum_required(VERSION 3.24)

project(Yamc)
set(CMAKE_CXX_STANDARD 20)

FILE(GLOB SOURCE_FILES src/*.cpp)

add_executable(Yamc
        ${SOURCE_FILES}
        deps/glew/src/glew.c
        deps/lodepng/lodepng.c
        deps/noise/noise.c
        deps/sqlite/sqlite3.c)

add_subdirectory(deps/glfw)
include_directories(deps/glew/include)
include_directories(deps/glfw/include)
include_directories(deps/lodepng)
include_directories(deps/noise)
include_directories(deps/sqlite)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if(APPLE)
    target_link_libraries(Yamc glfw
            ${GLFW_LIBRARIES})
endif()

if(UNIX)
    target_link_libraries(Yamc dl glfw
            ${GLFW_LIBRARIES})
endif()

