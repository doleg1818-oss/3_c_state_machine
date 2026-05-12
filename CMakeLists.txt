cmake_minimum_required(VERSION 3.16)

project(c_state_machine C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(state_machine_example
    examples/main.c
    src/state_machine.c
)

add_executable(test_state_machine
    tests/test_state_machine.c
    src/state_machine.c
)