cmake_minimum_required(VERSION 3.17)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 20)

include_directories(

        "/usr/local/opt/mpfr/include"
        "/usr/local/opt/gmp/include"
        "/usr/local/opt/mpfi/include"
)




add_executable(cpp_playground  main.cpp)

target_link_libraries(cpp_playground

        "/usr/local/opt/mpfr/lib/libmpfr.6.dylib"
)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
