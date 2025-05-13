# Калькулятор матриц (Matrix Calculator)

Библиотека для работы с матрицами, предоставляющая широкий набор матричных операций:

- Сложение и вычитание матриц
- Умножение матриц
- Вычисление определителя
- Транспонирование
- Нахождение обратной матрицы
- Вычисление ранга матрицы
- Возведение матрицы в степень

## Зависимости ПО

### Утилиты

- CMake (>= 3.10)
- C++ компилятор с поддержкой C++17
- Doxygen (для генерации документации)
- dpkg (для создания DEB пакетов)

### Заимствованный код

Проект разработан полностью самостоятельно, без использования заимствованного кода.

## Сборка ПО

### Пошаговая инструкция по сборке

1. Клонирование репозитория:

```bash
git clone https://vgit.mirea.ru/karpov.d.a3/tspp-2025-2.git
cd matrix-calculator
```

2. Создание директории для сборки:

```bash
mkdir build
cd build
```

3. Конфигурация и сборка проекта:

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

4. Запуск тестов:

```bash
ctest --verbose
```

### Файлы для поставки

- `main_app` - исполняемый файл калькулятора матриц
- `*.deb` - пакет для установки в системах на базе Debian/Ubuntu

## Запуск

### Использование программы

Программа принимает две матрицы через аргументы командной строки в формате:

```bash
main_app "rows cols matrix1_data" "rows cols matrix2_data"
```

Пример:

```bash
main_app "2 2 1 2 3 4" "2 2 2 0 1 2"
```

Это создаст и выполнит операции над матрицами:

```
Матрица A:
1 2
3 4

Матрица B:
2 0
1 2

A + B:
3 2
4 6

A * B:
4 4
10 8
```

### Пример использования библиотеки

```cpp
int main(int argc, char *argv[])
{
    try
    {
        if (argc != 3)
        {
            printUsage();
            return 1;
        }

        Matrix A = parseMatrixFromString(argv[1]);
        Matrix B = parseMatrixFromString(argv[2]);

        std::cout << "Матрица A:" << std::endl;
        A.display();
        std::cout << "\nМатрица B:" << std::endl;
        B.display();

        std::cout << "\nA + B:" << std::endl;
        (A + B).display();
        std::cout << "\nA * B:" << std::endl;
        (A * B).display();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```

## Авторы

- **Дмитрий Карпов** - _разработчик_ - [gitlab](https://vgit.mirea.ru/karpov.d.a3)
