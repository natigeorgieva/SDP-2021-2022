# Упражнение 9

## Task 0.1

Да се напише програма, която да въвежда в опашка числа докато не се въведе нещо различно от число. След прекратяване на въвеждането да се сортират, числата от опашката на четни и нечетни в съответни други две опашки. След сортирането да се изпишат на екрана стойностите на опашките.

```
Пример: 
    Вход: 
        10 56 73 45 23 90 87 34 stop
    Изход: 
        Odd: 73 45 23 87
        Even: 10 56 90 34
```

## Task 0.2

Да се напише програма, която по въведени две опашки да прави следното:
    
* Да събира предните два елемента на опашните и да слага техния сбор в трета
* Елементите на двете опашки да се премахват и да се вкарат обратно в тях
* Този процес да продълж и q пъти, където q е дължината на по-голямата опашка

Резултатната опашка да се върне от фунцкията

```
Пример:
    Вход: 
        10 56 73 45 23 90 87 34 stop
        9 87 23 12 43 stop
    Изход: 
        19 143 96 57 66 99 174 57

```



## Task 1 
Напишете функция, която по подадена опашка проверява дали елементите й са палиндром.
```
    10 90 78 1 78 90 10 - Палиндром
    10 20 30 30 21 10   - Не е палиндром
    1 2 3 4 5 5 4 3 2 1 - Палиндром
```


## Task 2

Напишете функция, която по подадена опшка да проверява дали тя е сортирана в нарастващ ред.

```
    front        back
      |           |
     50 40 30 20 10  - Не е сортирана в нарастащ ред
     89 76 90 32 11  - Не е сортирана
     10 20 30 40 50  - Сортирана в нарастващ ред
```

## Task 3 

Напишете фунцкия, която по подадени две опашки да провери дали те са сортирани в растящ ред и ако са да връща опашка, която съдържа елементите на двете опашки също сортирани. В противен случай да връща празна опашка.

```
Пример 1:
    10 20 30 40 50
    15 15 20 25 33 44 55

    Изход: 10 15 15 20 20 25 30 33 40 44 50 55

Пример 2:
    89 76 90 32 11
    10 20 30 40 50

    Изход: Не сортирана опашка терминиране на процеса....
```

## Task 4

Напишете фунцкия, която по даденa опашка от опашки да връща опашка от опашки с тези опашки, чиято сума от елементите е в интервала [a,b]

## Task 5

Да се реализира алгоритъм, който сортира опашка с рекурсия без да изпозва други спомагателни структури. Използвайте реализирания от вас алгоритъм да сортирате опашките от задача 2, ако те не са сортирани предварително.