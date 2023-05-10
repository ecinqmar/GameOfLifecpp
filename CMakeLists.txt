# Almost all CMake files should start with this
# You should always specify a range with the newest
# and oldest tested versions of CMake. This will ensure
# you pick up the best policies.
cmake_minimum_required(VERSION 3.1)

project(
    GameofLife
    VERSION 1.0
    LANGUAGES CXX
)


add_library( GameofLifeLib cells.cpp cells.hpp )

add_executable( LifeExec main.cpp )

target_link_libraries(LifeExec PRIVATE GameofLifeLib )