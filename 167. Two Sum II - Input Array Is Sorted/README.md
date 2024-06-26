https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

related: https://github.com/SkosMartren/leetcode_com/tree/main/1.%20Two%20Sum

* Наличие сортировки позваляет решить за O(1) по памяти с помощью двух указателей (167. Two Sum II - Input Array Is Sorted)
* при отсутствии сортировки придется воспользоваться дополнительной памятью (1. Two Sum)
____

Два указателя -- надо сначала найти инвариант?

[Павел Маврин. Два указателя](https://vk.com/wall-194505932_266)

*numbers.begin() + *next(numbers.begin()) <= target <= *prev(numbers.end()) + *prev(prev(numbers.end()))
____

[Разбор задачи 167 leetcode.com Two Sum II - Input array is sorted. Решение на C++](https://www.youtube.com/watch?v=xj6YMf4IOks)


1. Совсем плохо - перебираем все пары индексов из исходного массива, смотрим, не равна ли сумма этих чисел target.

O(n^2) по времени   
O(1) по памяти

2. Лучше, но не учитывает специфику задачи. 

а + b = target <=> b = target - а.


Если известно 'а' - тогда 'b' мы знаем - парное ему число.

а) можно создать unordered_тар - там хранить значения, которые есть в исходном массиве. Ключ - число, значение - позиция, где оно встречается.

Нельзя использовать один элемент 2 раза - поэтому можно заполнять unordered_тар в том же проходе, в каком по нему искать. Когда ищем элемент, его ещё нет в unordered_mар.

O(n) по времени - оптимально  
O(n) по памяти

б) идём по числам, двоичным поиском ищем второе число.  
lowеr_bound/upper_bound.

О(nlogn) по времени - субоптимально  
O(1) по памяти - оптимально

3. Правильный.

Если идти по числам подряд (по возрастанию индексов), 
то  
'а' возрастает  
b = target - а - уменьшается.

Позиция того, что найдёт двоичный поиск, может только продвинуться к началу.

Более выгоден линейный поиск, а не двоичный. 

Два указателя.

Один индекс идёт с начала - берём первый элемент суммы

Второй переходит на первое с конца число <= заданному 'target - а'. Если получили == - значит нашли ответ.

O(n) по времени - оптимально  
O(1) по памяти - оптимально


Про переполнения.  
а = [1, 2, INT_МАХ], аге = 3  
Первое же сравнение 1 + INT_МАХ > tагеt  
1 + INT_МАХ - UB. Вероятное значение - INT_MIN  

а = [INT_MIN, -2, -1], target = -3

Что делать: безопасные сравнения.
    
<img src="https://github.com/SkosMartren/useful-materials/blob/main/for_167_leetcode_1.png" width="1500" height="700"/>

<p align="center"> Демонстрация работы sumGreater для if (b < 0 && a < INT_MIN - b) {return false;} </p>
