
Перенести рекурсивное решение в preoder-обход!

__________

https://leetcode.com/problems/same-tree/

https://walkccc.me/LeetCode/problems/0100/

related: https://github.com/SkosMartren/leetcode_com/tree/main/101.%20Symmetric%20Tree -- разница только в порядке передачи левой и правой ноды при обходе

В 100 и 101 preorder обход!

__________

[Разбор задачи 100 leetcode.com Same Tree. Решение на C++](https://www.youtube.com/watch?v=Od0Oq8hNT3Q)

100a.cpp == рекурсивный DFS == preorder == my_code_preoder.cpp   
100b.cpp ==  не рекурсивный DFS  

1. Рекурсивное решение.

деревья равны:  
а) оба nullptr  
б) оба не nullptr, при этом val в корнях совпадает - и левые поддеревья совпадают между собой, правые поддеревья совпадают между собой.

O(n) по времени, O(height) по памяти

2. Нерекурсивное решение.

Храним в стеке/очереди список пар вершин, которые нужно сравнить.

Сначала заносим исходную пару. Извлекаем очередную -  
а) если оба nullptr - пропускаем  
б) если один nullptr - завершаем, ответ false  
в) если оба не nullptr - сравниваем val, если не равны - false, если равны - заносим в стек/очередь заносим потомков.

O(n) по времени и O(n) по памяти.

3. Плохие способы:

Сереализовать оба дерева, потом сравнить как строки.
Лишаемся короткой схемы [возможности прекратить работу как только получили информацию о том, что деревья различны]

__________
