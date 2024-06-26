https://leetcode.com/problems/valid-parentheses/

https://walkccc.me/LeetCode/problems/0020/

Если встретили закрывающую скобку, то _**последняя**_ открывающая должна быть того же типа!

* существует открывающая скобка на вершине стека, того же типа, что и закрывающая --> удаляем с вершины
* существует открывающая скобка на вершине стека, НЕ того же типа, что и закрывающая --> return false
* НЕ существует открывающая скобка на вершине стека, того же типа, что и закрывающая --> return false
* если не было выхода в рамках цикла, то возвращаемое значение имеет имеет вид: return stack.empty() -- причина тому, например, тест: $((()$ -- в стеке остануться две скобки, для которых нет закрывающих

test 1

    )(
_________

[Разбор задачи 20 leetcode.com Valid Parentheses. Решение на C++](https://www.youtube.com/watch?v=lXUmw5lzkTk&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

1. Наивное решение.

Найти в строке любую подстроку "()" или "{}" или "[]" - и удалить, повторить процедуру. 
Если удалось получить пустую строку такими операциями - ответ "да", исходная последовательность правильная скобочная последовательность, иначе нет.

О(n^2) по времени, где n - длина исходной строки.  
O(n) по памяти.

2. Оптимальное решение.

Проходим по строке один раз слева направо, используем стек. 
Если встречаем открывающую направо, используем стек. 
Если встречаем открывающую скобку - закидываем в стек парную ей закрывающую.

На вершине стека - первая не закрытая на текущий момент скобка.

Если встречаем закрывающую - смотрим, не пуст ли стек, сравниваем со скобкой, которую нужно закрыть.
Если совпадает - убираем скобку со стека, если не совпадает - ответ "нет".

После прохода нужно убедиться, что стек пуст. Если пуст - ответ "да", если не пуст - "нет".
ответ "да", если не пуст - "нет".

O(n) по времени  
O(n) по памяти

