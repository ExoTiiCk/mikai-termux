# CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
set(LIBRARY_NAME mikai)
project(${LIBRARY_NAME} LANGUAGES C VERSION 4.10 DESCRIPTION "library to manage a MyKey for Termux")

# C11 standard
set(CMAKE_C_STANDARD 11)

# Set release if unset
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Include directories
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBNFC REQUIRED libnfc)

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2 -s")

# Add source files
file(GLOB SOURCES "src/*.c")
add_library(${LIBRARY_NAME} SHARED ${SOURCES})

# Link libraries
target_link_libraries(${LIBRARY_NAME} ${LIBNFC_LIBRARIES})

# Install rules
install(TARGETS ${LIBRARY_NAME}
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

# Install headers
install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")
