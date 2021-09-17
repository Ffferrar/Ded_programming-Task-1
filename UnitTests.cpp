#include <stdio.h>
#include "unittest.h"
#include "defines.h"



void UnitTest (){                       // ��������� ��� �������������� ���� �����
    double roots[2];
    test_printer(1, 1, 1, 0, roots, 1); // (a, b, c, ���������� ������, �����, ����� �����

}





void test_printer (double a, double b, double c,int right_num_roots, double roots[2], int testnum)           // ��������� ��������� ����� � �������� ��������� ����-������
{
    double x1 = 0, x2 = 0;
    int nroots = SolvingEquation (a, b, c, &x1, &x2);

    if (nroots==right_num_roots)                    // ���� ���������� ������ ���������, ��������� �� �� ���������
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

    else                              // ���� ���������� ������ ������, �� ������� ������ ������ �������. �� ����, ��� ��������� �������
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
// �� ����� �������� ���� � �� �� �������,
//������� �������� ����� �������� ������� � ������� ����� � ������ ����


/* if ( test_solver(1,1,1,0) == 0 )
    {
        printf ("Test #1 failed,
        */


