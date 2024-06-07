cmake_minimum_required(VERSION 3.10)
project(MyServerClient)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directories for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the source files
add_executable(Server src/server.cpp)
add_executable(Client src/client.cpp)

# Link pthread library
target_link_libraries(Server pthread)
target_link_libraries(Client pthread)

# Add compiler flags
target_compile_options(Server PRIVATE -Wall -Wextra -Werror -Wpedantic)
target_compile_options(Client PRIVATE -Wall -Wextra -Werror -Wpedantic)
