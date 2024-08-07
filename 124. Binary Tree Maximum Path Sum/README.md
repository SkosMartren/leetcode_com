https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/603423/python-recursion-stack-thinking-process-diagram/ -- разбор

https://walkccc.me/LeetCode/problems/124/

У Федора Меньшикова разбор отсут-т!

___

Основная идея состоит в том, чтобы для каждого узла дерева определить максимальную сумму пути, которая проходит через этот узел, и обновить глобальную максимальную сумму пути.

1. Для каждого узла:
* Рассчитываем максимальную сумму пути в левом поддереве.
* Рассчитываем максимальную сумму пути в правом поддереве.
2. Максимальная сумма пути, проходящего через текущий узел, равна сумме значений текущего узла, максимальной суммы пути в левом поддереве и максимальной суммы пути в правом поддереве.
3. Обновляем глобальную переменную, хранящую максимальную сумму пути.
4. Возвращаем максимум между суммой текущего узла и одного из его поддеревьев (либо левого, либо правого), чтобы этот результат мог быть использован в родительском узле.


Доказательство правильности

Рекурсивный расчет максимальной суммы пути:
Для каждого узла рекурсивно вычисляем максимальную сумму пути в левом и правом поддеревьях. Это гарантирует, что мы рассматриваем все возможные пути в поддеревьях.

Актуализация глобальной переменной:
Переменная max_sum обновляется на каждом узле, если текущая сумма пути больше, чем значение max_sum. Это гарантирует, что мы всегда имеем максимальную сумму пути, проходящего через любые узлы дерева.

Возвращение максимального пути:
Возвращаем значение, включающее текущий узел и максимум из путей в левом и правом поддеревьях. Это позволяет корректно учитывать путь, который может быть использован в родительском узле.


Рекурсивный вызов для левого и правого поддеревьев: Рекурсивно вычисляем максимальные суммы путей для левого (L) и правого (R) поддеревьев. Если сумма меньше 0, используем 0, так как отрицательная сумма уменьшила бы общую сумму пути.

Вычисление суммы пути через текущий узел: Вычисляем сумму пути, проходящую через текущий узел RootSum, как сумму значения текущего узла root->val и сумм путей левого и правого поддеревьев (L и R).

Обновление глобальной максимальной суммы пути: Обновляем глобальную переменную Sum, если RootSum больше текущего значения Sum.

Возвращение максимальной суммы пути, включающей текущий узел: Возвращаем значение текущего узла плюс максимальная сумма между левым и правым поддеревом, чтобы верхний уровень мог использовать этот результат в своей вычислениях.

_____

https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

visualization algorithms: https://youtu.be/6cA_NDtpyz8?t=143

- положим, искомым является MaxPathSum
- очевидно, каждую node надо проверять на возможность быть ответом, например: [-1,-2,-3], [-1,-2,-3,4,-5,-6,-7]. Поэтому при решение будем использовать postorder обход
- Также важным тестом является [1,2,3]
- если ветка текущего поддерева имеет сумму < 0, то данную ветку не рассматрвиаем
<!---
- идея решения заключается в слияние листов в max(root->left->val, root->right->val, 0), перед этим в выполнить MaxPathSum = max(root->left->val, root->right->val)
-->

Решение удобно предсталвять через призму postorder и деревьях вида


<br>

         1
        / \
     NULL   NULL

         1
        / \
     NULL   3

       1
      / \
    2     3


             -3
             / \
           -1   -2  
         
              3
             / \
            1   2  
         
              3
             / \
            1   -2  

<br>

         Начальное значение int Sum = -1001; обусловленно 
         
         The number of nodes in the tree is in the range [1, 3 * 104].
         -1000 <= Node.val <= 1000

         т.е. гарантировано существует хотя бы одна нода, которая гарантировано больше -1001
<br>

         пояснение к

    int L = max(PostOrder(root->left), 0);
    int R = max(PostOrder(root->right), 0);            

             -1
             / \
           -3   -2  

    В этом случае возвращаем -1, делается это посредством строки
    int RootSum = root->val + L + R;

<br>

         Sum = max(Sum, RootSum); -- обновление ответа

<br>

         Демонстрация к return root->val + max(L, R);

              3                  3
             / \         --->      \
            1   2                    2
            
                  1000
                  /
               -1
               /
             1000


         Теперь понимаем каким должен быть выход из рекурсии при nullptr:

             if(root == nullptr){
                 return 0;
             }
