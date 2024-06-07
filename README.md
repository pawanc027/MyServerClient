# Client-Server Program with Data Reversal

This project includes a simple client-server application written in C++20. The client sends arbitrary data to the server, and the server responds with the reversed data.

## Features

- Client application to send data to the server.
- Server application to receive data from the client and return it in reverse.
- Uses modern C++20 features.
- CMake build system for easy compilation.

## Prerequisites

- C++20 compatible compiler (e.g., GCC, Clang)
- CMake (version 3.10 or higher)

## Directory Structure

ClientServer/
├── CMakeLists.txt
├── README.md
└── src/
    ├── client.cpp
    └── server.cpp

## Build Instructions

  mkdir build
  cd build
  cmake ..
  cmake --build .

## Running the Applications

1. Start the server:
   ./bin/Server

2. Run the client:
   ./bin/Client

   The client will prompt you to enter a message, which it will send to the server. The server will then reverse the message and send it back to the client. The client will display the reversed message.
