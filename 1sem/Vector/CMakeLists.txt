cmake_minimum_required(VERSION 3.14)
project(VectorProject)

# Указываем стандарт C++ (C++11 или выше)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Сборка основной программы
add_executable(main_app main.cpp Vector.cpp)

# 2. Подключение Google Test (CMake скачает его автоматически, если его нет в системе)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Для Windows: предотвращаем переопределение настроек компилятора GTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 3. Сборка исполняемого файла с тестами
add_executable(vector_tests test_Vector.cpp Vector.cpp)

# Линкуем тесты с библиотекой GTest
target_link_libraries(vector_tests gtest_main)

# Включаем возможность запуска тестов через команду ctest
include(GoogleTest)
gtest_discover_tests(vector_tests)