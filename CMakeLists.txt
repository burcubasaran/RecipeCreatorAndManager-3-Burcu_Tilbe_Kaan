cmake_minimum_required (VERSION 3.1)
project("Recipe-Manager" CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(Recipe-Manager helloworld.cpp)
target_link_libraries(Recipe-Manager cppcms sqlite3)
