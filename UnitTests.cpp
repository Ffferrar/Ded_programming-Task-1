#include <stdio.h>
#include "unittest.h"
#include "defines.h"



void UnitTest (){                       // прописаны все использующиеся юнит тесты
    double roots[2];
    test_printer(1, 1, 1, 0, roots, 1); // (a, b, c, количество корней, корни, номер теста

}





void test_printer (double a, double b, double c,int right_num_roots, double roots[2], int testnum)           // Принимает параметры теста и печатает результат юнит-тестов
{
    double x1 = 0, x2 = 0;
    int nroots = SolvingEquation (a, b, c, &x1, &x2);

    if (nroots==right_num_roots)                    // Если количество корней совпадает, проверяем на их равенство
    {
        switch(nroots)
        {
            case 0: printf("Test #%d passed\n", testnum);
                    break;

            case 1: if (x1==roots[0])
                    {
                        printf("Test #%d passed\n", testnum);
                    }
                    else
                    {
                        printf("Test #%d failed\nExpected result: %f\nActual result: %f\n", testnum, roots[0], x1);
                    }
                    break;

            case 2: if ( (x1==roots[0] && x2==roots[2]) || (x2==roots[0] && x1==roots[2]) )
                    {
                        printf("Test #%d passed\n", testnum);
                    }
                    else
                    {
                        printf("Test #%d failed\nExpected result: %f %f\nActual result: %f %f\n", testnum, roots[0], roots[2], x1, x2);
                    }
                    break;

            case INFINITE_NROOTS: printf("Test #%d passed: \n", testnum);
                    break;
        }
    }

    else                              // если количество корней разное, то смотрим каждый случай отдельн. Не знаю, как упростить решение
    {
        switch(right_num_roots)
        {
          case 0: switch(nroots)
                  {
                        case 1: printf("Test #%d failed: Expected result: No roots \nActual result: %f\n", testnum, x1);
                                break;
                        case 2: printf("Test #%d failed: Expected result: No roots \nActual result: %f %f\n", testnum, x1, x2);
                                break;
                        case INFINITE_NROOTS:
                                printf("Test #%d failed: Expected result: No roots \nActual result: Any number\n", testnum);
                                break;
                  }


          case 1: switch(nroots)
                  {
                        case 0: printf("Test #%d failed: Expected result: %f \nActual result: No roots\n", testnum, roots[0]);
                                break;
                        case 2: printf("Test #%d failed: Expected result: %f \nActual result: %f %f\n", testnum, roots[0], x1, x2);
                                break;
                        case INFINITE_NROOTS:
                                printf("Test #%d failed: Expected result: %f \nActual result: Any number\n", testnum, roots[0]);
                                break;
                  }


          case 2: switch(nroots)
                  {
                        case 0: printf("Test #%d failed: Expected result: %f %f \nActual result: No roots\n", testnum, roots[0], roots[1]);
                                break;
                        case 1: printf("Test #%d failed: Expected result: %f %f \nActual result: %f\n", testnum, roots[0], roots[1], x1);
                                break;
                        case INFINITE_NROOTS:
                                printf("Test #%d failed: Expected result: %f %f \nActual result: Any number\n", testnum, roots[0], roots[1]);
                                break;
                  }


          case INFINITE_NROOTS:
                  switch(nroots)
                  {
                        case 0: printf("Test #%d failed: Expected result: Any number \nActual result: No roots\n", testnum);
                                break;
                        case 1: printf("Test #%d failed: Expected result: Any number \nActual result: %f\n", testnum, x1);
                                break;
                        case 2:
                                printf("Test #%d failed: Expected result: Any number \nActual result: %f %f\n", testnum, x1, x2);
                                break;
                  }

        }




    }

}
// по циклу вызываем одну и ту же функцию,
//которая вызывает самую корневую функцию и выводит текст в случае чего


/* if ( test_solver(1,1,1,0) == 0 )
    {
        printf ("Test #1 failed,
        */


