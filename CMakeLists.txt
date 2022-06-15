cmake_minimum_required(VERSION 3.1.0)

project(t VERSION 0.1.0)

include(CTest)
enable_testing()

if (WIN32)
    set(SDL2_DIR ${CMAKE_SOURCE_DIR}/SDL2)
    set(GLEW_DIR ${CMAKE_SOURCE_DIR}/glew)
endif (WIN32)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(OpenGL)

add_executable(t main.cpp window.cpp shader.cpp buffers.cpp)

target_link_libraries(t ${SDL2_LIBRARIES} ${GLEW_LIBRARIES}  ${OPENGL_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)