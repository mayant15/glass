cmake_minimum_required(VERSION 3.18)
project(dub)
set(CMAKE_CXX_STANDARD 17)

# Generate a compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include paths for all targets
include_directories(${CMAKE_SOURCE_DIR}/dub/include)

###############################################################################
# Core dub library
###############################################################################

set(DUB_LIBRARY_SOURCES
    dub/src/dub.cpp
)

add_library(dub ${DUB_LIBRARY_SOURCES})

###############################################################################
# dub cli executable 
###############################################################################

set(DUB_EXECUTABLE_SOURCES
    cli/src/main.cpp
)

add_executable(dub-cli ${DUB_EXECUTABLE_SOURCES})
target_link_libraries(dub-cli PUBLIC dub)

###############################################################################
# sample executables for testing
###############################################################################

add_executable(hello test/hello.cpp)

