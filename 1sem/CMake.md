
#cmake #C #ComputerScience


https://www.youtube.com/watch?v=LZwEtbc9 - источник 
https://www.youtube.com/watch?v=96bYXEwwvF0&list=PL84DYBRflqZcx3Hi_6X7kl3fMhLIuSSMq&index=2 - обучающее видео от ЛИРС КФУ

**Вариант 1.**  Минимальный CMakeList.txt 

```cmake
cmake_minimum_required(VERSION 3.0)
# это комментарии
# название проекта, можно не вводить, но это чревато проблемами
project(HelloWorld)

#имя исполняемого файла (здесь main), который собирается из main.cpp
add_executable(main main.cpp)

# это тоже можно не вводить. Указано, что для офрмирования main используем C++ (CXX) с укааанием стандарта
set_target_properties(
    main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON

```


Файл лежит в папке с main.cpp. Рекомендуется создать папку build (mkdir build). Перейти в эту папку (cd ./build). Внутри этой папки вызвать 
`cmake ..`
Две точки означает, что требуется искать файл в папке на уровень выше.  Далее собираем проект и создаем исполняемый файл. Исполняемый файл создаться в папке build. 
```bash
cmake --build .
```

**Вариант 2.**  Сборка проекта из нескольких файлов.  Использование переменных. 

```cmake
cmake_minimum_required(VERSION 3.1)
project(example2)
#Переменная объявляется вместе с ее инициализацией
set(SOURCES 
	    main.cpp
	    hello.cpp
)
set(HEADERS
	    hello.h
)
# 
Переменная используется в виде ${SOURCE}
add_executable(main ${SOURCES} ${HEADERS})
set_target_properties(
    main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
```