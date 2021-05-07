Задание к шаблонам - чтобы компилировался следующий код

```
double Square(double x) {
  return x * x;
}

double MakeNonnegative(double x) {
  if (x < 0) {
    return 0;
  } else {
    return x;
  }
}

Matrix<double> matrix = Identity(2);
matrix[0][1] = -2;
matrix[1][0] = -3;
std::cout << FindMin(matrix) << std::endl;  // минимум во всей матрице
std::cout << Apply(matrix, Square) << std::endl;  // применить Square к матрице
std::cout << Apply(matrix, MakeNonnegative) << std::endl;  // применить MakeNonnegative к матрице

/* 
Вывод:
-3
1 4 
9 1
1 0
0 1
*/
```

Только за шаблон матрицы и FindMin будет 6. За Apply еще 4 (всего 10).

+4 балла за определитель матрицы

+6 за RowwiseApply, которая вычисляет некую функцию по каждому ряду таблицы и возвращает результат в виде вектора, например:
```
0 1 7
-4 0 1
-2 -1 0
```
Если к каждому ряду применить функцию, находящую минимум, вернется {0, -4, -2}   
`// RowwiseApply(matrix, RowMin) == {0, -4, -2}`

Если применить функцию, находящую сумму, вернется {8, -3, -3}                    
`// RowwiseApply(matrix, RowSum) == {8, -3, -3}`
