cmake_minimum_required(VERSION 3.22)

project(ecs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(
    ECS_SOURCES
    src/component.cpp
    src/entity.cpp
    src/entity_manager.cpp
    src/systems_runner.cpp
)

add_library(${PROJECT_NAME} STATIC ${ECS_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(
    ECS_TEST_SOURCES
    tests/entity_manager_tests.cpp
)

add_executable(${PROJECT_NAME}_test ${ECS_TEST_SOURCES})

target_link_libraries(${PROJECT_NAME}_test GTest::gtest_main ecs)

target_include_directories(${PROJECT_NAME} PUBLIC tests)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}_test)

