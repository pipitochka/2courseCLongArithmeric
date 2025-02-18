# Long arithemrtic
практикум №1, реализация быстрой арифметики

## Содержание
- [Установка](#начало-работы)
- [Подключение](#Подключение)
- [Использование](#Использование)
- [Тесты](#Тесты)

## Установка
Соберите проект:
```sh
$ mkdir build && cd build
$ cmake ..
$ make
```
## Подключение
В файле, где будут использоваться числа
```cpp
#include "include/BigDecimal.h"
```
В CMakeList
```cmake
file(GLOB BIGDECIMAL_SOURCES src/*.cpp)
add_library(BIGDECIMAL ${BIGDECIMAL_SOURCES})
target_link_libraries(YOUR_TARGET BIGDECIMAL)
```

## Использование

Создать переменную типа BigDecimal можно при помощи конструктора от строки, от строки с указанием точности(дробной части) и от double,
в последнем случае точность будет фиксированна и равна 20 знакам после запятой, можно поменять при помощи макроса PRECISION 
```cpp
BigDecimal bg1 = BigDecimal("1.23");
BigDecimal bg2 = BigDecimal("1.23", 5);
BigDecimal bg3 = 1.23_longnum;
```
Класс поддерживает все стандартные операции, а так же ввод и вывод через консоль 
```cpp
BigDecimal bg4 = bg2 - bg1; 
BigDecimal bg5 = bg2 * bg1;
std::cout << bg5;
```

## Тесты
Тесты будут находиться в папке test, запустить их можно следубщими командами
```sh
$ tests
$ ./tests
```