#C, #ComputerScience 

По мотивам роликов
https://www.youtube.com/watch?v=c7CasTJKw7o 
[https://www.lektorium.tv/speaker/2936](https://www.lektorium.tv/speaker/2936) Основы C++, первый семестр | Евгений Линский

**Этапы компиляции **

Запуск препроцессора. На выходе получим (текстовый) файл со всем включенным кодом 

``` 
	gcc -E hello.cpp > hello_prep.cpp 
``` 

Компиляция в объектный файл 
```
	gcc -c hello_prep.cpp 
```

Создание исполняемого файла
```
	g++ hello_prep.o -o hello.exe
``` 
Ключ -o указывает что имя исполняемого файла будет hello.exe. Без этого будет создан (исполняемый) файл a.exe

Если написать 
```
	g++ hello.cpp -o hello.exe 
```
то все этапы пройдут автоматически (обычно так и компилируем наш код)

Установив утилиту objdump, можно посмотреть как выглядит код на ассемблере 
```
	objdump -d hello_prep.o
```

Этапы компиляции 
	Препроцессор -> Ассемблер -> Машинный код

Линковка (собирание нескольких файлов в один)
~~~C
/*  main.c */
	int main(){
		hello();
		return 0;
	}

///////////////////
// hello.c
	void hello(){
		printf("Hello! \n"); 
	}
~~~

```
gcc main.c hello.c -o main.exe
```

Далее обсуждается как связать файлы через заголовочные файлы
 
Ссылки 
- https://parallel.uran.ru/book/export/html/25 
- https://cppinsights.io/  онлайн-сервис, показывает как преобразует код компилятор
- Статья об анализаторе кода под windows https://www.deleaker.com/blog/2020/01/04/valgrind-for-windows/  (для linux https://en.wikipedia.org/wiki/Valgrind)
