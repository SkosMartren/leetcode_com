https://leetcode.com/problems/squares-of-a-sorted-array/description/

https://walkccc.me/LeetCode/problems/0977/ == two ptr

related: https://github.com/SkosMartren/leetcode_com/tree/main/88.%20Merge%20Sorted%20Array -- связь через проход с конца для ответа

У Федора Меньшикова разбор отсут-т!

____


Ввиду " non-decreasing order" [== nums отсортирован] будем заполнять искомый вектор справа налева, кладя $max(nums[LeftBorderWindow] * nums[LeftBorderWindow], nums[RightBorderWindow ] * nums[RightBorderWindow])$ 
в $nums[i]$ и сдвигая границу окна в зависимости от того, какой элемент положили: 

- если $nums[LeftBorderWindow] * nums[LeftBorderWindow]$, то сдвигаем $LeftBorderWindow$ вправа, то есть прибавляем 1

- если $nums[RightBorderWindow] * nums[RightBorderWindow]$, то сдвигаем $RightBorderWindow$ влева, то есть вычитая 1

При этом не забываем после каждой вставки сдвигать i влево, то есть вычитать 1. 
