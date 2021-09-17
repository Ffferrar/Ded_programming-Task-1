#include <stdio.h>
#include <stdlib.h>
#include "unittest.h"
#include <math.h>
#include "defines.h"

/**
    Unit-test function
    @return Information about tests

    Test-printer function
    @param[in] a a-coefficient
    @param[in] b b-coefficient
    @param[in] c c-coefficient
    @param[in] right_num_roots expected number of roots
    @param[in] roots expected roots of equation
    @param[in] testnum number of teest

    @return Printing test-information

*/


void UnitTest (){
    double *roots= (double*)calloc(2, sizeof(double));

    roots[0]=-1;
    test_printer(1, 2, 1, 1, roots, 1);

    roots[0]=0;
    test_printer(0, 5, 0, 1, roots, 2);

    roots[0]=-3; roots[1]=2.0/3;
    test_printer(3, 7, -6, 2, roots, 3);

    roots[0] = (3-sqrt(41))/8; roots[1] = (3+sqrt(41))/8;
    test_printer(-4, 3, 2, 2, roots, 4);
}

void test_printer (double a, double b, double c,int right_num_roots, double *roots, int testnum)
{
    double x1 = 0, x2 = 0;
    int nroots = SolvingEquation (a, b, c, &x1, &x2);

    if (nroots==right_num_roots)                    // Если количество корней совпадает, проверяем на их равенство
    {
        switch(nroots)
        {
            case 0: printf("Test #%d passed\n", testnum);
                    break;

            case 1: if (IsZero(x1,roots[0]))
                    {
                        printf("Test #%d passed\n", testnum);
                    }
                    else
                    {
                        printf("Test #%d failed\nExpected result: %.2f\nActual result: %f\n", testnum, roots[0], x1);
                    }
                    break;

            case 2: if ( (IsZero(x1,roots[0]) && IsZero(x2,roots[1])) || (IsZero(x2,roots[0]) && IsZero(x1,roots[1])) )
                    {
                        printf("Test #%d passed\n", testnum);
                    }
                    else
                    {
                        printf("Test #%d failed\nExpected result: %f %f\nActual result: %f %f\n", testnum, roots[0], roots[1], x1, x2);
                    }
                    break;

            case INFINITE_NROOTS: printf("Test #%d passed: \n", testnum);
                    break;
            default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);

        }
    }

    else                              // если количество корней разное, то смотрим каждый случай отдельно. Не знаю, как упростить решение
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
                        default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);

                  }
                  break;

          case 1: switch(nroots)
                  {
                        case 0: printf("Test #%d failed: Expected result: %f \nActual result: No roots\n", testnum, roots[0]);
                                break;
                        case 2: printf("Test #%d failed: Expected result: %f \nActual result: %f %f\n", testnum, roots[0], x1, x2);
                                break;
                        case INFINITE_NROOTS:
                                printf("Test #%d failed: Expected result: %f \nActual result: Any number\n", testnum, roots[0]);
                                break;
                        default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);

                  }
                  break;

          case 2: switch(nroots)
                  {
                        case 0: printf("Test #%d failed: Expected result: %f %f \nActual result: No roots\n", testnum, roots[0], roots[1]);
                                break;
                        case 1: printf("Test #%d failed: Expected result: %f %f \nActual result: %f\n", testnum, roots[0], roots[1], x1);
                                break;
                        case INFINITE_NROOTS:
                                printf("Test #%d failed: Expected result: %f %f \nActual result: Any number\n", testnum, roots[0], roots[1]);
                                break;
                        default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);
                  }
                  break;

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
                        default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);
                  }
                  break;
          default: printf("UnitTests(): ERROR: nRoots = %d/n", nroots);
        }




    }

}



