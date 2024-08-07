https://leetcode.com/problems/line-reflection/ -- CLOSED

https://walkccc.me/LeetCode/problems/0356/

https://github.com/doocs/leetcode/tree/main/solution/0300-0399/0356.Line%20Reflection -- медленное решение, на walkccc лучше!

У Федора Меньшикова разбор отсут-т!
___

На собесе дали https://leetcode.com/problems/line-reflection, но с изменениями: там дублировались точки, и это надо было учитывать, в то время как на литкоде все можно слить в один хеш-сет.

Например, на литкоде пример: 
[0,1], [0,-1], [0,1]
Выдает true,
На собесе же було false, так как для [0,1] нет ещё одной точки [0,-1] (т.е. отрезки могут накладываться). Пускай тот, кто сдаёт ,внимательно смотрят примеры (мне сначала дали условие, начал решать, а потом через минуты 2 дали примеры, так что пускай всю инфу ждут от интервьюера)

Также помимо перегрузки хеш-функции надо было перезагрузить operator==, так как дали дефолтно структуру

Поэтому см. my_code_general.cpp -- более общее верное решение
___________

https://www.lintcode.com/problem/908/

___________

Если ответ true, то существует **одна** такая прямая, параллельная оси OY, которая симетрична отражает заданные точки

если на вход пришла одна точка, то ответ в любом случае true

Положим, на вход пришло две точки. Тогда неоходимо проверить, что у них просто совпадают координата $y$ с помощью метода CheckCoordinate

Положим, на вход пришло по меньшей мере четыре точки. Не ограничивая общности, рассмотрим из них четыре таких: $(x_1, y_1)$, $(x_2, y_1)$, $(x_3, y_2)$, $(x_4, y_2)$
, что они удовлетворяют как условию задачи, так и $x_1 < x_3$, $x_2 < x_4$. Тогда имеет место система: 


$x_3 = x_1 - dx$

$x_4 = x_2 + dx$


Геометрическая интерпретация системы:
![ alt](https://github.com/SkosMartren/useful-materials/blob/main/for_356_leetcode_1.png)


Сложив уравнения системы, получаем уравнение: $x_3 + x_4 = x_1 + x_2 = const$ -- так как точки выбирались произвольно, то уравнение верно для любых точек, при условии, что выполняется условие задачи. 
Чтобы найти $const$, найдем $(x_{min}, y')$, $(x_{max}, y')$ -- если такой пары не сущетсвуте, ответ на задачу false, иначе $x_{min} + x_{max}= const$

Что примечательно, также это работает и для точки. Обратися к графику и рассмотрим $(4,4)$, cnt = 8 --> (8-4,4) существует в входных данных

```objectivec
int x_min = points.front().front();
int x_max = points.back().front();
unordered_map<pair<int, int>, bool, PairHash> PointToExist; // необходимо для реализации CheckCoordinate

for(const auto& point : points){

  const int x = point[0];
  const int y = point[1];
  x_min = min(x_min, x);
  x_max = max(x_max, x);
  if(!PointToExist[{x,y}]){++PointToExist[{x,y}] = 1;}
}
```

Зная $const$, реализуем CheckCoordinate:

```objectivec
// можно ли из двумерной координаы получить уникальный id?
bool CheckCoordinate(const vector<vector<int>>& points, unordered_map<pair<int, int>, bool, PairHash>& PointToExist, const int cnt/* = x_min + x_max*/){
  for(auto point : points){

    if(!PointToExist[{cnt - point[0], point[1]}]){return false;}
  }
  return true;
}
```
Реализуем хеш-функцию: 

```objectivec
struct PairHash{
size_t operator()(const pair<int, int> p) const{ // передавать pair<int, int> по ссылке или нет?
  
  return (size_t)(h_i_1(p.first) * 37 * 37 + h_i_1(p.second) * 37 + 117);
}
hash<int> h_i_1;
hash<int> h_i_2;
};
```

Конечный код имеет вид: 
```objectivec
struct PairHash {
	size_t operator()(const pair<int, int> p) const { // передавать pair<int, int> по ссылке или нет?

		return (size_t)(h_i_1(p.first) * 37 * 37 + h_i_1(p.second) * 37 + 117);
	}
	hash<int> h_i_1;
	hash<int> h_i_2;
};


// тип cnt <-- "-108 <= points[i][j] <= 10^8"
 // "const" будет ошибкой, так как можем обратится к несущест-у элементу в "PointToExist[{cnt - point[0], point[1]}]"
bool CheckCoordinate(const vector<vector<int>>& points, /*const*/ unordered_map<pair<int, int>, bool, PairHash>& PointToExist, const int cnt/* = x_min + x_max*/) {
	for (/*const*/ auto point : points) { // "const" будет ошибкой, так как можем обратится к несущест-у элементу в "PointToExist[{cnt - point[0], point[1]}]"

		if (!PointToExist[{cnt - point[0], point[1]}]) { return false; }
	}
	return true;
}

/*
Если расположить PairHash ниже CheckCoordinate, то в MSVS будет ошибка: Error (active)	E0308	more than one instance of overloaded function "CheckCoordinate" matches the argument list:	
*/

bool isReflected(const vector<vector<int>>& points) {

	if (points.empty()) { return true; } // проверка пустого points -- такой тест есть в тестирующей системе
	int x_min = points.front().front();
	int x_max = points.back().front();
	unordered_map<pair<int, int>, bool, PairHash> PointToExist; // необходимо для реализации CheckCoordinate

	for (const auto& point : points) {

		const int x = point[0];
		const int y = point[1];
		x_min = min(x_min, x);
		x_max = max(x_max, x); 
		if (!PointToExist[{x, y}]) { PointToExist[{x, y}] = true; }

	} // отрезок, проходящий через (x_min, y*) и (x_max, y*) будет иметь максимальную длину. Примечательно, что не получатся рассуждения через поиск концов отрезка минимальной длины!

	// if(PointToExist.size() % 2 == 1){return false;} // check it!
	return CheckCoordinate(points, PointToExist, x_min + x_max);
}

```

___________

<p align="center"> 25/36 test cases </p>

	[[0,0]]
 true
