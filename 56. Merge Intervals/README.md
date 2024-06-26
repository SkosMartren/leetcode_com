https://leetcode.com/problems/merge-intervals/description/

related 
- https://github.com/SkosMartren/leetcode_com/tree/main/986.%20Interval%20List%20Intersections -- обратная задача: надо найти пересечение, а в исходной -- объединение    
- https://github.com/SkosMartren/leetcode_com/tree/main/763.%20Partition%20Labels -- аналог

https://github.com/doocs/leetcode/tree/main/solution/0000-0099/0056.Merge%20Intervals

https://walkccc.me/LeetCode/problems/0056/

__________

[Разбор задачи 56 leetcode.com Merge Intervals. Решение на C++](https://www.youtube.com/watch?v=PIUaSD1c0AY)

0. Наивный подход. Берём каждый исходный отрезок - и ищем, с какими он имеет пересечения. Потенциально 0(n^2). 

Худший случай - нет пересечений, нужно каждый с каждым сравнить, чтобы понять, что это действительно так.

1. Группировка интервалов по тому, какие могут быть объединены.

Сортируем по левой границе интервала.

Если интервал не слился со следующим (а у него минимальное значение левой границы) - то со следующими после 
него интервал точно не сольётся.

Если слился - можем рассматривать объединённый интервал - и сливать со следующими. 

правая граница слитого - тах из правых границ исходных слитых интервалов.

После сортировки O(n) - один проход по интервалам.

Сортировка занимает O(nlogn) по времени, в std::sort O(logn) по памяти.

____

Замечание:   

При формировании тестов надо рассмотреть три случия: 

1. Вложенность  
2. Пересечение слева  
3. Пересечение справа

          /*
          У двух отрезков нет пересечения в двух случиях: 
          
                  /1/
          a1|----------|a2
                           b1|-------|b2  
                       
                  /2/
                                         a1|----------|a2
                           b1|-------|b2   
          
          Что зквивалентно в логическом виде:  
          a2 < b1 || b2 < a1 -- заметим, что a1, b1 по одну сторону знака неравенства, тогда, имеет место запись: 
          max(a1, b1) > max(a2, b2) > min(a2, b2) -- это более сильное условие, нежели просто max(a1, b1) > max(a2, b2)
          Если инвертировать: 
          a2 >= b1 && b2 >= a1 
          max(a1, b1) <= min(a2, b2)
          получим условие пересечения
          */
          
          /*
          max в 41 строке необходим ввиду того, что есть два вида положения правой границы при пересечении: 
          
          инваринат b1 <= a1 ввиду sort Intervals
          
                  /1/
          interval                      a1|--|a2
          Covers.back()            b1|-------------|b2
          
                  /2/
          interval                       a1|----------|a2
          Covers.back()             b1|-------|b2   
          
          
          Нет пересечения: 
          
          interval                                    a1|----------|a2
          Covers.back()             b1|-------|b2  
          
          */
