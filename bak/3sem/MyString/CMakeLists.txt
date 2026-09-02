cmake_minimum_required(VERSION 3.1)

project(proba2)

set(SOURCES 
    main.cpp
    hello.cpp
    String.cpp
)

set(HEADERS
    hello.h
    String.h
)

add_executable(main ${SOURCES} ${HEADERS})

#это можно не писать - это требования к версии стандарта
set_target_properties(
    main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)