https://leetcode.com/problems/robot-bounded-in-circle/

https://walkccc.me/LeetCode/problems/1041/

У Федора Меньшикова разбор отсут-т!

___________

We do not need to run 4 cycles to identify the limit cycle trajectory. One cycle is enough. There could be two situations here.

First, if the robot returns to the initial point after one cycle, that's the limit cycle trajectory.

Second, if the robot doesn't face north at the end of the first cycle, that's the limit cycle trajectory.
Once again, that's the consequence of the plane symmetry for the repeated cycles [proof].

<p align="center">Appendix: Mathematical Proof</p>

Let's provide a strict mathematical proof.

If the robot doesn't face north at the end of the first cycle, then that's the limit cycle trajectory.

First, let's check which direction the robot faces after 4 cycles.

Let's use numbers from 0 to 3 to mark the directions:
north = 0, east = 1, south = 2, west = 3.
After one cycle the robot is facing direction k != 0.

After 4 cycles, the robot faces direction (k * 4) % 4 = 0, i.e. after 4 cycles, the robot is always facing north.

Second, let's find the robot coordinates after 4 cycles.

The robot initial coordinates are $x = y = 0$. After one cycle, the new coordinates are $x_1 = x + \Delta x$, $y_1 = y + \Delta y$, where both $\Delta x$ and $\Delta y$ could be positive or negative.

Let's consider four situations.

After one cycle, the robot faces north. Then here is what we have after 4 cycles:

$x_4 = x + \Delta x + \Delta x + \Delta x + \Delta x = x + 4 \Delta x$

$y_4 = y + \Delta y + \Delta y + \Delta y + \Delta y = y + 4 \Delta y$

After one cycle, the robot faces east. Then here is what we have after 4 cycles:

$x_4 = x + \Delta x + \Delta y - \Delta x - \Delta y = x$

$y_4 = y + \Delta y - \Delta x - \Delta y + \Delta x = y$

After one cycle, the robot faces south. Then here is what we have after 4 cycles:

$x_4 = x + \Delta x - \Delta x + \Delta x - \Delta x = x$

$y_4 = y + \Delta y - \Delta y + \Delta y - \Delta y = y$

After one cycle, the robot faces west.
Then here is what we have after 4 cycles:

$x_4 = x + \Delta x - \Delta y - \Delta x + \Delta y = x$

$y_4 = y + \Delta y - \Delta x - \Delta y + \Delta x = y$


"На бесконечной плоскости робот изначально стоит в точке (0, 0) и обращен лицом на ***север***."

Нам не нужно запускать 4 цикла, чтобы определить траекторию предельного цикла. Одного цикла вполне достаточно. Здесь могут быть две ситуации.

Во-первых, если робот возвращается в исходную точку после одного цикла, это **предельная траектория цикла**.

Во-вторых, если робот *не поворачивается лицом на **север** в конце первого цикла*, это **предельная траектория цикла**.
Еще раз, это следствие плоской симметрии для повторяющихся циклов [доказательство].

<p align="center">Приложение: Математическое доказательство</p>

Давайте приведем строгое математическое доказательство.

Если робот не поворачивается лицом на север в конце первого цикла, то это предельная траектория цикла.

Сначала давайте проверим, в какую сторону повернут робот после 4 циклов.

Давайте используем цифры от 0 до 3, чтобы обозначить направления:
север = 0, восток = 1, юг = 2, запад = 3.
После одного цикла робот поворачивается лицом в направлении k != 0.

После 4 циклов робот поворачивается лицом в направлении (k * 4) % 4 = 0, т.е. после 4 циклов робот всегда смотрит на север.

Во-вторых, давайте найдем координаты робота после 4 циклов.

Начальные координаты робота равны $x = y = 0$. После одного цикла новыми координатами будут $x_1 = x + \Delta x$, $y_1 = y + \Delta y$, где как $\Delta x$, так и $\Delta y$ могут быть положительными или отрицательными.

Давайте рассмотрим четыре ситуации.

После одного цикла робот поворачивается лицом на ***север***. Тогда вот что мы имеем после 4 циклов:

$x_4 = x + \Delta x + \Delta x + \Delta x + \Delta x = x + 4 \Delta x$

$y_4 = y + \Delta y + \Delta y + \Delta y + \Delta y = y + 4 \Delta y$

После одного цикла робот поворачивается лицом на восток.
Тогда вот что мы имеем после 4 циклов:

$x_4 = x + \Delta x + \Delta y - \Delta x - \Delta y = x$

$y_4 = y + \Delta y - \Delta x - \Delta y + \Delta x = y$

После одного цикла робот поворачивается лицом на юг. Тогда вот что мы имеем после 4 циклов:

$x_4 = x + \Delta x - \Delta x + \Delta x - \Delta x = x$

$y_4 = y + \Delta y - \Delta y + \Delta y - \Delta y = y$

После одного цикла робот поворачивается лицом на запад.
Тогда вот что мы имеем после 4 циклов:

$x_4 = x + \Delta x - \Delta y - \Delta x + \Delta y = x$

$y_4 = y + \Delta y - \Delta x - \Delta y + \Delta x = y$

___________

Рассмотирим один проход по instructions как способ задания вектора на двумерное плоскости. При это, набор "L" и "R" в конечном итоге будет задавать поворот вектора. Изначально, по услвоию, вектор направлен на north (север) [в положительном направлении оси OY]. Рассмторим случаи: 
- если после одного прохода по instructions робот поворачивается в направлении west / east (запада / востока) [[в отрицательном / положительном направлении оси OX], то на момент конца 4 прохода робот вернется в исходную точку. В качестве мотивировки это можно прочувствовать нарисовав путь:
<img src="https://leetcode.com/problems/Figures/1041/pic2.png" width="750" height="600"/>

<img src="https://leetcode.com/problems/Figures/1041/pic4.png" width="750" height="600"/>

  Докажем это на основе [матрицы поворота](https://ru.wikipedia.org/wiki/%D0%9C%D0%B0%D1%82%D1%80%D0%B8%D1%86%D0%B0_%D0%BF%D0%BE%D0%B2%D0%BE%D1%80%D0%BE%D1%82%D0%B0):
  
  Положим 
  - $(x', y')$ -- вектор, проведенный из точки $(0, 0)$ в конец пути робота, на момент окончания 4 прохода.
  - $(x, y)$ -- вектор, получившийся после одного прохода по instructions (по сути в задаче сумма 2 / 4 векторов с поворотом на 180 / 90 градусов
  
  $$
  {\begin{pmatrix} x' 
  \\  
  y' \end{pmatrix} } = {\begin{pmatrix} \cos { 0 }& \mp \sin { 0 } \\ 
  \pm \sin { 0 }& \cos { 0 } \end{pmatrix}} {\begin{pmatrix} x 
  \\  
  y \end{pmatrix} } + {\begin{pmatrix} \cos { \frac{\pi}{2} }& \mp \sin { \frac{\pi}{2} } \\ 
  \pm \sin { \frac{\pi}{2} }& \cos { \frac{\pi}{2} } \end{pmatrix}} {\begin{pmatrix} x 
  \\  
  y \end{pmatrix} } + {\begin{pmatrix} \cos { \pi }& \mp \sin { \pi } \\ 
  \pm \sin { \pi }& \cos { \pi } \end{pmatrix}} {\begin{pmatrix} x 
  \\  
  y \end{pmatrix} }  + {\begin{pmatrix} \cos { \frac{3 \pi}{2} }& \mp \sin { \frac{3\pi}{2} } \\ 
  \pm \sin { \frac{3\pi}{2} }& \cos { \frac{3\pi}{2} } \end{pmatrix}} {\begin{pmatrix} x 
  \\  
  y \end{pmatrix} } = {\begin{pmatrix} 0 
  \\  
  0 \end{pmatrix} }
  $$

отсюда видно, что если робот смотрел в конце каждого из 4 циклов в разные стороны, то он вернется в результате в исходную точку. Гарантируется, что робот будет смотреть в каждую точку, если после первого цикла он не смотрит на север. 

* Если смотрим на запад / восток, то будет просто поварачиваться по противочасовой/часовое стрелке на 90 градусов. За 4 цикла вернется обратно
* Если смотрит на юг, то просто вернеться в исходную точку за два цикла, пройдя путь обратно.
* Также возможно что за один цикл он вернется в исходную точку, тогда направление не важно

Ввиду вышесказаного возвращаемое значение имеет вид: return (X == 0 && Y == 0) || SideWorld != 0; 

Разворот осуществляется через подсчет по модулю 4
