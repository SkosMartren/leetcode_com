https://leetcode.com/problems/container-with-most-water

https://walkccc.me/LeetCode/problems/0011/

_______

[Разбор задачи 11 leetcode.com Container With Most Water. Решение на C++](https://www.youtube.com/watch?v=eauynef2Qts)

0. Наивное решение - перебираем две перегородки, которые оставим. 

Площадь = min(высот) * расстояние

Сложность O(n^2)

1. Монотонность: чем выше уровень воды, который можно удержать - тем меньше расстояние между крайними перегородками, между которыми эту воду можно оставить.

Нас интересует произведение - оно не монотонно.

12=12*1=6*2=4*3=3*4=2*6=1*12

Точно знаем, что левая граница при повышении уровня удерживаемой воды может только сдвигаться вправо.

Правая граница может только сдвигаться влево.

Минимальная высота - min из внешних границ.

Получаем площадь при каждой рассмотренной высоте.

Ищем ближайшие границы, обеспечивающие большую высоту.

Две границы разного размера - одну можно оставить и не двигать 

Два указателя.
