cmake_minimum_required(VERSION 3.0)
project(HelloWorld)
add_executable(main main.cpp)

set_target_properties(
    main PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)