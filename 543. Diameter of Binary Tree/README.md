https://leetcode.com/problems/diameter-of-binary-tree/description/

https://walkccc.me/LeetCode/problems/543/

___

https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B_%D0%BD%D0%B0_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D1%8C%D1%8F%D1%85

центр дерева это вершина максимально удаленная от других вершин. в дереве центр это либо одна вершина либо две, находящаяся(находящиеся) в середине пути между двумя самыми удаленными вершинами. чтобы найти две самых удаленых вершины в дереве (за расстояние между соседними вершинами считаем 1) можно использовать два поиска в ширину (для дерева можно и DFS). сначала найдем от любой вершины x самую удаленную от неё вершину y, затем найдем вершину z, самую удаленную от y. путь из y в z — это один из самых больший путей в графе.

https://leetcode.com/problems/minimum-height-trees/description/

___

[Разбор задачи 543 leetcode.com Diameter of Binary Tree. Решение на C++](https://www.youtube.com/watch?v=wtbQc9Myi_Y&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

1. Неоптимально: начинаем с каждой вершины - и 
запускаем поиск в ширину.

У диаметра есть конечная вершина - обходим все 
остальные, перебирая вторую конечную вершину.

O(n) по памяти, n - число узлов - для обхода с любой 
вершины нам нужен в дереве указатель на родителя.

O(n^2) по времени - n вершин в качестве начала, O(n) 
один обход дерева, начиная с этой вершины.

2. Универсальное - так можно найти диаметр любого 
дерева, в том числе не двоичного.

Начинаем с любой вершины, ищем самую дальнюю вершину - 
обход всех вершин. запускаем второй обход с этой 
вершины - опять находим самую дальнюю вершину. 
Расстояние между этими двумя вершинами - и есть 
диаметр.

O(n) по памяти - нужен указатель "вверх" по дереву. 

O(n) по времени - оптимально.

3. Заточенное под задачу. без выделения дополнительной 
памяти.

Искомый путь может быть а) сверху вниз - от корня и до 
самого дальнего листа. Длина - высота дерева.
б) есть вершина, до которой путь идёт вверх, потом 
вниз. В этой вершине - найти высоту левого поддерева и 
высоту правого поддерева - длина пути с "перевалом" в 
этой вершине - это сумма этих высот деревьев.

Нужно находить высоты всех поддеревьев. (высоту левого 
и правого поддерева - и добавляем 1).

Для каждой вершины - учитываем эти два варианта - или 
максимальная высота одного поддерева, или сумма высот 
поддеревьев. Находим максимум из этих значений - по 
всем вершинам.

Обход рекурсивный -

O(height) по памяти (стек) 
O(n) по времени