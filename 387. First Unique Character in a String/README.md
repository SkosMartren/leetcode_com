https://leetcode.com/problems/first-unique-character-in-a-string/description/

https://walkccc.me/LeetCode/problems/0387/

У Федора Меньшикова разбор отсут-т!
_________

Алгоритм решения: два прохода...
1. сортировка подсчетом
2. проход по строке и поиск первого символа, количество которого при сортировке подсчетом равно 1

Time complexity : $\mathcal{O}(N)$ since we go through the string of length N two times.  
Space complexity : $\mathcal{O}$ because English alphabet contains 26 letters.

_________

Дополнительный материал:

Лакман Макдауэл - Карьера программиста (2020)

условие: страница 82, задача 1.1.

Реализуйте алгоритм, определяющий, все ли символы в строке встречаются только один раз. А если при этом запрещено использование дополнительных структур данных?

решение: страница 197

_______

А почему в предложенном решении используется "const string &" вместо "string_view"?

Ответ от "Фёдор Меньшиков":

Алексей, разница между string_view и const string& небольшая, если их использовать только при доступе к конкретному элементу, а при вызове функции передавать string, а не const char *.

Алексей, const string & это ссылка (указатель) на исходную строку + запрет операций модификации. string_view это указатель на символы строки + её размер. Отсюда видно, что string_view чуток предпочтительнее, поскольку там доступ более прямой. Там мы сразу имеем доступ к массиву символов, а const string& это ссылка (указатель) на объект строки, в котором лежит указатель на массив символов.
