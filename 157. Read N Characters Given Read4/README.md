https://leetcode.com/problems/read-n-characters-given-read4/description/

https://walkccc.me/LeetCode/problems/157/

https://github.com/doocs/leetcode/tree/main/solution/0100-0199/0157.Read%20N%20Characters%20Given%20Read4

related: https://github.com/doocs/leetcode/blob/main/solution/0100-0199/0158.Read%20N%20Characters%20Given%20read4%20II%20-%20Call%20Multiple%20Times/README_EN.md  

___

https://prepfortech.io/leetcode-solutions/read-n-characters-given-read4  

https://evanyang.gitbooks.io/leetcode/content/LeetCode/read_n_characters_given_read4.html

___

# Тип char * в C++

    char * (указатель на char) — это тип данных в C++, который используется для хранения адреса первого символа строки или массива символов. Указатели char * часто используются для работы с строками в стиле C, которые завершаются нулевым символом ('\0').
    
    Документация
    Вы можете ознакомиться с официальной документацией по указателям в C++ на сайте cppreference.
    
    Пример использования
    Давайте рассмотрим тривиальный пример использования char * для работы со строками.
    
    
    
    #include <iostream>
    #include <cstring> // для функций работы со строками
    
    int main() {
        // Создание строки в стиле C
        char str[] = "Hello, world!";
        
        // Указатель на первый символ строки
        char *p = str;
        
        // Вывод строки с использованием указателя
        std::cout << "String: " << p << std::endl;
        
        // Изменение символа через указатель
        p[7] = 'W';
        
        // Вывод измененной строки
        std::cout << "Modified string: " << p << std::endl;
        
        // Использование указателя для прохождения по строке
        while (*p != '\0') {
            std::cout << *p;
            p++;
        }
        std::cout << std::endl;
        
        return 0;
    }
    
    Объяснение:
    Создание строки: char str[] = "Hello, world!"; — создается строка в стиле C.
    Указатель на строку: char *p = str; — создается указатель p, который указывает на первый символ строки str.
    Вывод строки: std::cout << "String: " << p << std::endl; — выводится строка с использованием указателя. Это работает потому, что оператор << для std::cout знает, как работать с указателями на строки.
    Изменение символа: p[7] = 'W'; — изменяется символ в строке через указатель.
    Вывод измененной строки: std::cout << "Modified string: " << p << std::endl; — выводится измененная строка.
    Проход по строке: while (*p != '\0') { ... } — используется цикл для прохода по строке с помощью указателя, пока не будет достигнут нулевой символ ('\0').
    Этот пример показывает базовые операции с использованием указателей на строки в стиле C, такие как создание строки, изменение символов и проход по строке с использованием указателя.

# int*

     рассмотрим пример использования указателя на int (int*) в C++.
    
    Пример использования int*
    Пример включает следующие операции:
    
    Создание массива целых чисел.
    Использование указателя для прохода по массиву.
    Изменение значений в массиве через указатель.
    
    
    #include <iostream>
    
    int main() {
        // Создание массива целых чисел
        int arr[] = {10, 20, 30, 40, 50};
        int size = sizeof(arr) / sizeof(arr[0]);
    
        // Указатель на первый элемент массива
        int* ptr = arr;
    
        // Вывод массива с использованием указателя
        std::cout << "Original array: ";
        for (int i = 0; i < size; i++) {
            std::cout << *(ptr + i) << " ";
        }
        std::cout << std::endl;
    
        // Изменение значений в массиве через указатель
        for (int i = 0; i < size; i++) {
            *(ptr + i) += 10;
        }
    
        // Вывод измененного массива
        std::cout << "Modified array: ";
        for (int i = 0; i < size; i++) {
            std::cout << *(ptr + i) << " ";
            //std::cout << ptr[i] << " "; // good!
        }
        std::cout << std::endl;
    
        return 0;
    }
    Объяснение:
    Создание массива: int arr[] = {10, 20, 30, 40, 50}; — создается массив целых чисел.
    Определение размера массива: int size = sizeof(arr) / sizeof(arr[0]); — вычисляется количество элементов в массиве.
    Указатель на массив: int* ptr = arr; — создается указатель ptr, который указывает на первый элемент массива arr.
    Вывод массива: for (int i = 0; i < size; i++) { std::cout << *(ptr + i) << " "; } — используется цикл для прохода по массиву с помощью указателя и вывода значений. Оператор *(ptr + i) используется для доступа к элементу массива.
    Изменение значений: for (int i = 0; i < size; i++) { *(ptr + i) += 10; } — используется цикл для прохода по массиву с помощью указателя и увеличения каждого элемента на 10.
    Вывод измененного массива: Снова используется цикл для прохода по массиву и вывода измененных значений.
    Этот пример показывает базовые операции с использованием указателей на целые числа в C++, такие как доступ к элементам массива, изменение значений и проход по массиву с использованием указателя.
