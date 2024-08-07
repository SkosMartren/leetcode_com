https://leetcode.com/problems/remove-duplicates-from-sorted-array/

https://walkccc.me/LeetCode/problems/0026/

У Федора Меньшикова разбор отсут-т!

analogue: https://github.com/SkosMartren/leetcode_com/tree/main/283.%20Move%20Zeroes

related: https://github.com/SkosMartren/leetcode_com/tree/main/80.%20Remove%20Duplicates%20from%20Sorted%20Array%20II

___________

i-CountDuplicates = CountUnique

#  <p align="center"> Алгоритм для my_code_with_my_unique.cpp </p>

## <p align="center"> Пример 1 </p>

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 23 	| 23 	| 24 	| 25 	| end          	|
|      	| ^  <br> first <br> result 	|    	|    	|    	|    	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 23 	| 23 	| 24 	| 25 	| end          	|
|      	| ^   <br> result 	|   ^  <br> first  	|    	|    	|    	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 23 	| 23 	| 24 	| 25 	| end          	|
|      	| ^   <br> result 	|     	|   ^  <br> first 	|    	|    	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 23 	| 23 	| 24 	| 25 	| end          	|
|      	| ^   <br> result 	|     	|    	|    ^  <br> first	|    	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 23 	| 0 	| 25 	| end          	|
|      	|  	|    ^   <br> result 	|    	|    ^  <br> first	|    	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 23 	| 0 	| 25 	| end          	|
|      	|  	|    ^   <br> result 	|    	|    	|   ^  <br> first 	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 23 	| 0 	| 25 	| end          	|
|      	|  	|    	|  ^   <br> result   	|    	|   ^  <br> first 	| ^  <br> last 	|


|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 25 	| 0 	| 0 	| end          	|
|      	|  	|    	|  ^   <br> result   	|    	|   ^  <br> first 	| ^  <br> last 	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 25 	| 0 	| 0 	| end          	|
|      	|  	|    	|  ^   <br> result   	|    	|     	| ^  <br> last  <br> first	|

|  idx 	|             0             	| 1  	| 2  	| 3  	| 4  	| 5            	|
|:----:	|:-------------------------:	|----	|----	|----	|----	|--------------	|
| nums 	|             23            	| 24 	| 25 	| 0 	| 0 	| end          	|
|      	|  	|    	|    	|   ^   <br> result  	|    	| ^  <br> last  <br> first 	|


## <p align="center"> Пример 2 состояние 1 </p>


```objectives
ForwardIt UNIQUE(ForwardIt first, ForwardIt last) {
    
    if (first == last) {return last;} 
 
    ForwardIt result = first;
    ...
}
```

|  idx 	|    0    	| 1  	| 2  	| 3  	| 4  	| 5      	|
|:----:	|:-------:	|----	|----	|----	|----	|--------	|
| nums 	|    15   	| 16 	| 17 	| 18 	| 19 	| end    	|
|   iterators   	| ^ <br> first <br>	result |    	|    	|    	|    	| ^ <br> last 	|

Ожидается для заданого nums, что в конечном итоге result = last, а конечное состояние будет иметь вид:  

|  idx 	|    0    	| 1  	| 2  	| 3  	| 4  	| 5      	|
|:----:	|:-------:	|----	|----	|----	|----	|--------	|
| nums 	|    15   	| 16 	| 17 	| 18 	| 19 	| end    	|
|   iterators   	|  |    	|    	|    	|    	| ^ <br> last <br>	result <br> first 	|

Достаточно естественно ожидать, что в UNIQUE необходим цикл с шагом 1 по {first, ..., last}.  
Напишем самый тривиальный [надо же с чего-то начать] цикл и заметим, что на основе пример 1 и таблицы конечного  
состояния примера 2 можно утверждать, что возвращаемое значение будет иметь вид: return ++result;  

Запишем код:

```objectives
ForwardIt UNIQUE(ForwardIt first, ForwardIt last) {
    
    if (first == last) {return last;} 
 
    ForwardIt result = first;
    for (;first != last; ++first){
    ...
    }
    ...
    return ++result;
}
```

## <p align="center"> Пример 2 состояние 2 </p>

Выполним одну итерацию цикла:

|  idx 	|    0    	| 1  	| 2  	| 3  	| 4  	| 5      	|
|:----:	|:-------:	|----	|----	|----	|----	|--------	|
| nums 	|    15   	| 16 	| 17 	| 18 	| 19 	| end    	|
|   iterators   	| ^ <br> result |  ^ <br> first  	|    	|    	|    	| ^ <br> last 	|

Так как знаем желаемый результат, ожидаемо, что к концу итерации состояиние должно иметь вид: 

|  idx 	|    0    	| 1  	| 2  	| 3  	| 4  	| 5      	|
|:----:	|:-------:	|----	|----	|----	|----	|--------	|
| nums 	|    15   	| 16 	| 17 	| 18 	| 19 	| end    	|
|   iterators   	|  |  ^ <br> first  <br> result 	|    	|    	|    	| ^ <br> last 	|

при этом, если result == first, то result не двигается [см. пример 1], иначе же [как видно из Пример 2 состояние 2] сдвигается.  
Запишем это условие в коде:

```objectives
ForwardIt UNIQUE(ForwardIt first, ForwardIt last) {
    
    if (first == last) {return last;} 
 
    ForwardIt result = first;
    for (;first != last; ++first){
        if ((*result != *first)) {
            ++result;
            *result = move(*first);
        }
    }
    
    return ++result;
}
```

При проверке кода выясняем, что он работает.

_____________________

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Ме Бэ, [7/4/2023 1:46 AM]
Друзья, а зачем в Possible implementation (https://en.cppreference.com/w/cpp/algorithm/unique) в

unique (1)
```objectives
template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;
 
    ForwardIt result = first;
    while (++first != last)
        if (!(*result == *first) && ++result != first)
            *result = std::move(*first);
 
    return ++result;
}
```

строка: ++result != first во втором условном операторе?

Ме Бэ, [7/4/2023 1:49 AM]
если что — я закоментировал эту строку и сдал сюда: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ — задача была сдана


Андрей Таусинов, [7/4/2023 12:45 PM]
Целиком условие в комментарии стало:
//         if (!(*result == *first) && ++result != first)   ?
Но тогда ведь мы result перестаем сдвигать.
Или только само сравнение?

По идее, это защита от кольцевых контейнеров, чтобы не задублировать в конце первый элемент, больше ничего в голову не приходит

Соответветственно для большинства контейнеров эта строчка роли не играет

Ме Бэ, [7/4/2023 2:38 PM]
"для большинства контейнеров эта строчка роли не играет" — а разве в C++ по умолчанию есть колцевые контейнеры? Так понимаю, эта заглшука на случай пользовательских кольцевых контейнеров?

Андрей Таусинов, [7/4/2023 2:42 PM]
Вроде, нет, но я могу что-то не знать. В теории можно std::list зациклить, но это похоже на путь в никуда) Так что да скорее всего расчет именно на пользовательские
