cmake_minimum_required(VERSION 3.22)
project(sglogger)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()

include_directories(include)

add_library(${PROJECT_NAME} STATIC sg_logging.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
