cmake_minimum_required(VERSION 3.12)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2 main.cpp Server.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.cpp Solver.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h)