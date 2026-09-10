cmake_minimum_required(VERSION 4.1)

project(HelloWorld)
add_executable(main main.cpp)

set_target_properties(
    main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)