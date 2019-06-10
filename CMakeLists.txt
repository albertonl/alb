cmake_minimum_required(VERSION 3.12)
project(alb)


set(CMAKE_CXX_STANDARD 17)

add_executable(alb src/main.cpp src/include/alb-program.hpp src/include/alb-statement.hpp src/include/Token.hpp src/include/tokens/BasicToken.hpp src/include/Tokenizer.hpp)
set_target_properties(alb PROPERTIES ENABLE_EXPORTS ON)
add_subdirectory(tests)
