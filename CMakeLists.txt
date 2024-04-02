cmake_minimum_required(VERSION 3.23)
project(Homework2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Dependencies
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)
FetchContent_MakeAvailable(glew)
# Our Project
set(SOURCE_FILES
    main.cpp 
    part4.h part4.cpp
    part3.cpp part3.h 
    sensor.cpp sensor.h airspeed.h
    airspeed.cpp altitude.h altitude.cpp angleofattack.h angleofattack.cpp 
    sensorfactory.h sensorfactory.cpp aerospacecontrolsystem.h aerospacecontrolsystem.cpp 
    robot.h robot.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw libglew_static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)