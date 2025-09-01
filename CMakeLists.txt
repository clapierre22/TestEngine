cmake_minimum_required(VERSION 3.10)
project(TestEngine C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add all .c files in src/
file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(TestEngine ${SRC_FILES})

# Example: Link SDL2 (if installed via package manager)
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(TestEngine ${SDL2_LIBRARIES})
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/base
    ${CMAKE_SOURCE_DIR}/src/render
    ${CMAKE_SOURCE_DIR}/src/logic
)
