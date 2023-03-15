cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER /home/zest/clang+llvm-15.0.2-x86_64-unknown-linux-gnu/bin/clang)
set(CMAKE_CXX_COMPILER /home/zest/clang+llvm-15.0.2-x86_64-unknown-linux-gnu/bin/clang++)

set(CMAKE_EXPORT_COMPILECOMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(ZzMain)
add_executable(main main.cpp)