https://leetcode.com/problems/binary-tree-level-order-traversal/description/

https://walkccc.me/LeetCode/problems/0102/

____

[Разбор задачи 102 leetcode.com Binary Tree Level Order Traversal. Решение на C++](https://www.youtube.com/watch?v=062En8ycnF0)

102a.cpp == preorder rec  
102b.cpp == inorder rec  
102c.cpp == postorder rec  
102d.cpp == not rec with / without reserve    

Лучше, чем O(n), где n - число вершин в дереве, сделать нельзя - каждую вершину нужно обойти, размер ответа тоже n.

Когда получим такие характеристики:

O(1) в среднем действий при посещении одной вершины. 

inorder: 
Обход (левое поддерево)-корень-(правое поддерево).

Саму вершину добавляем в соответствующий список.

preorder: 
Чтобы уровни добавлялись постепенно в массив ответа - можно 

корень-(левое поддерево)-(правое поддерево)

O(1) в среднем, если push_back для vector'ов уровней и для vector с уровнями.

O(n) по времени  
O(n) по памяти  

Если считать память кроме ответа - O(height).

Рекипсивное пешение ^^^  
Нерекурсивное решение: выделяем в список вершины одного уровня, 
проходим по этому списку как по очереди - получаем очередь с вершинами следующего уровня. 
В очереди указатели - при проходе дополнительно формируем значения.

O(n) по времени  
O(n) по памяти  
Если считать память кроме ответа - O(width) - максимальное количество вершин на одном уровне дерева.

можем делать reserve() для векторов со значениями на одном уровне - можем не выделять лишнюю память.


Главное, чтобы левое поддерево было посещено раньше правого [это можно увидеть на основе примера из условия]
