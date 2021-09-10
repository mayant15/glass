cmake_minimum_required(VERSION 3.18)
project(glass)
set(CMAKE_CXX_STANDARD 17)

# Generate a compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include paths for all targets
include_directories(${CMAKE_SOURCE_DIR}/glass/include)

###############################################################################
# Core glass library
###############################################################################

set(GLASS_LIBRARY_SOURCES
    glass/src/glass.cpp
)

add_library(glass ${GLASS_LIBRARY_SOURCES})

###############################################################################
# glass cli executable 
###############################################################################

set(GLASS_EXECUTABLE_SOURCES
    cli/src/main.cpp
    cli/src/repl.cpp
)

add_executable(glass-cli ${GLASS_EXECUTABLE_SOURCES})
target_link_libraries(glass-cli PUBLIC glass)

###############################################################################
# sample executables for testing
###############################################################################

add_executable(hello test/hello.cpp)

