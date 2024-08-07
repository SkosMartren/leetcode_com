https://leetcode.com/problems/rotate-image/

sol: 
- "rotate the image by 90 degrees (clockwise)."
- https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/

https://walkccc.me/LeetCode/problems/0048/

https://www.techiedelight.com/place-rotate-matrix-90-degrees-clock-wise-direction/

https://www.techiedelight.com/inplace-rotate-matrix-180-degrees/

https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/

https://www.geeksforgeeks.org/turn-an-image-by-90-degree/

____________

[Разбор задачи 48 leetcode.com Rotate Image. Решение на C++](https://www.youtube.com/watch?v=idYyTWRxQcA)

1. Обменивать по 4 элемента. 

Не просто O(n^2)

2. Поворот на 90 градусов формируем из двух действий:
- отражение относительно главной диагонали (транспонирование)
- отражение относительно горизонтальной или вертикальной середины.

____________

[Композицией двух осевых симметрий с непараллельными осями является поворот с центром в точке пересечения осей. При этом угол, на который поворачивается фигура, равен удвоенному углу между осями. Как и в случае со сдвигом, верно и обратное — любой поворот на плоскости раскладывается на две осевые симметрии.](https://etudes.ru/etudes/translation-rotation/)

Поворот по часовой стрелке на 90 градусов: сначала по горизонтали, затем по главной диагонали отображаем  
Поворот по часовой стрелке на 90 градусов: сначала по главной диагонали, затем по вертикали <-- [leetcode](https://leetcode.com/problems/rotate-image/solutions/3440564/animation-understand-in-30-seconds/)  
Поворот против часовой стрелке на 90 градусов: сначала по вертикали, затем по главной диагонали отображаем

Поворот на 180 градусов: композиция двух поворотов на 90 градусов OR один/два раза использования reverse: сначал по отношению к матрице, затем по отношению строкам матрицы (в зависимости от требований)

Проверить переход отражений во вращение удобно проверять на матрице вида: 

| 1 	| ... 	| 2 	|
|:-:	|:---:	|:-:	|
| : 	|  .  	| : 	|
| 3 	| ... 	| 4 	|
