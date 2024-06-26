https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

related: 
- https://leetcode.com/problems/intersection-of-two-arrays/
- https://github.com/SkosMartren/leetcode_com/tree/main/349.%20Intersection%20of%20Two%20Arrays

https://walkccc.me/LeetCode/problems/0350/

[Разбор задачи 350 leetcode.com Intersection of Two Arrays II. Решение на C++](https://www.youtube.com/watch?v=QgsZ3BI1Xc8&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

350a.cpp - unordered_map  | == сортировка подсчетом + два прохода  
350b.cpp - sort + Binary Search / lower_bound  
350c.cpp - sort + Binary Search / lower_bound - UPD 350b.cpp | как догадаться до " return p.num < v || (p.num == v && !p.present);"???? Ответ: [Returns an iterator pointing to the first element in the range \[first, last) such that element < value **(or comp(element, value)) is false**, (i.e. that is greater than or equal to value), or last if no such element is found.](https://en.cppreference.com/w/cpp/algorithm/lower_bound)  
350d.cpp - sort + Two Pointers == аналогичное решение в https://en.cppreference.com/w/cpp/algorithm/set_intersection - только на итераторах  
350e.cpp - UserHashTable

Самое оптимальное решение через бинарный поиск / два указателя  
После него: через unordered_map  
Все решения используют затраты по памяти по меньшей мере O(min(m,n))

_______________

1. unordered_map или самописная хэш-таблица. [350a.cpp или 350e.cpp]

* термин разбухание означает, во сколько раз больше данные занимают места при таком способе хранения, чем в идеальном случае.  
unordered_map<int,int> таблица с цепочками переполнения --> на каждую пару ключ-значение будет дополнительный указатель

unordered_map<int,int> - накладные расходы на одну пару ключ/значение ~ 24 байт - в 3 [ = 24 / (4 + 4) = 24 / ( sizeof(const key) + sizeof(value) )] раза больше, сама пара.   

==  
[  
pair<const key, value> kv = pair<const int, int> - 8 byte  
Так как цепочки переполнения, нужен указатель на следующее значение пары == Node* next - 8 byte  
элемент основной таблицы == size_t hash  
]  

Если в массиве все числа различные - то при занесении в unordered_map разбухание в ~ б [ ~= (24 - 4)/ (4) = (24 - sizeof(const key))/ (sizeof(int))] раз.
- память вида sizeof(const key) в любом бы случае потратилась на содержание элемента в массиве
- sizeof(int) - столько памяти потратится при хранении const key в массиве 

Самописная хэш-таблица: можем написать хэш-таблицу с открытым перемешиванием. Там разбухание будет в ~ 1.5 раза.

Можно разрешить: несколько одинаковых ключей - и не нужно будет хранить значение - сколько раз ключ встречался. Плохая алгоритмическая сложность.

Если хранить пары (число - количество), то разбухание будет в ~ 3 раза .

Алгоритм: сначала более короткий из массивов заносим в хэш-таблицу. Ключ - число из массива, значение - сколько раз встречалось. count[v]++.

Идём по более длинному массиву - ищем каждый его элемент в этой хэш-таблице. 
Если элемент есть и его количество не ноль - уменьшаем количество на 1, записываем это число в ответ

Сложность O(size(nums1) + size(nums2)) по времени,  
O(min(size(nums1), size(nums2))) по памяти.

Меньше нельзя - иначе не все элементы исходных массивов просмотрим.

Можно попробовать выиграть по времени...

2. Двоичный поиск.

На практике может обогнать unordered_map.

Сортируем массив меньшего размера. Формируем массив из пар (число, количество).

Идём по массиву большего размера - ищем двоичным поиском в меньшем массиве, 
если нашли и количество > 0 - тогда уменьшаем количество, записываем число в ответ.

Разбухание всего в 2 раза.

Время: O((minSize + maxSize) * log(minSize))

Память: O(minSize)

3. Follow up

Если оба отсортированы. Слияние массивов. Два указателя. 
Если значения равны - выписываем число в ответ, продвигаем оба указателя.

Если не равны - продвигаем указатель, указывающий на меньшее число.

Когда один из указателей прошёл весь массив - завершаем.

1 1 2 2 
 
2 2

Time:  O(mlogm+nlogn)  
Space: O(min(m,n))
_____

https://youtu.be/QgsZ3BI1Xc8?t=262

Несколько не понял 3 строку объяснения, вот мои попытки трактовки:

Доводы: утверждаем, что "unordered_map<int,int> count - накладные расходы на одну пару ключ/значение ~ 24 байт - в 3 раза больше, сама пара." — положим, это верно.
Теперь на вход передают два вектора: vector<int> nums1, vector<int> nums2 — nums1 / nums2 содержит уникальные элементы, при этом нет такого элемента в nums1, который бы содержался в nums2. Тогда, в count будет nums1.size() + nums2.size() элементов <= 2 * max(nums1.size(), nums2.size()) —-> в худшем случае разбухание будет в два раза больше, чем размер наибольшего вектора <---> "Если в массиве все числа различные - то при занесении в unordered_map разбухание в ~ б раз." — правильно понял мысль?

И еще вопрос:
"
unordered_map<int,int> - накладные расходы на одну пару ключ/значение ~ 24 байт - в 3 раза больше, сама пара.
"

Вы рассуждали примерно так же, как на видео в этом моменте: https://youtu.be/XamV5-pTNc8?t=2795
???

    struct Node{
      pair<const key, value> kv;
      Node* next; // указатель на следующую вершину. Обусловлен конструкций, схожей с "forwars_list". См лекцию + конспект к ШАДу
      size_t hash; // хеш текущего ключа
    };

vector используется вместо unordered_map в том случае, если удобно отображать индекс вектора в какое-то значение по этому индексу -- чаще всего это удобно при работе со строками, так как они ограничены алфавитом / кодировкой --> можно использовать постоянную память без аллокаций.


_____

related with https://en.cppreference.com/w/cpp/algorithm :

Set operations (on sorted ranges)  
- https://github.com/SkosMartren/leetcode_com/tree/main/2215.%20Find%20the%20Difference%20of%20Two%20Arrays
- https://github.com/SkosMartren/leetcode_com/tree/main/88.%20Merge%20Sorted%20Array
