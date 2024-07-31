cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(snowglobe LANGUAGES CXX)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

add_subdirectory(modules/ecs)

set(
    SOURCE_FILES
    src/main.cpp
    src/app.cpp
)

include_directories(src)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32> ecs)
