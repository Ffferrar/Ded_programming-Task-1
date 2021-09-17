#include <stdio.h>
#include <stdlib.h>
#include <assert.h>      // for assert
#include <math.h>       // for isfinites

#include "defines.h"  // for global variables
#include "unittest.h" // for my functions


/** The squire equations solver function

   @version Vers 2.0
   @date 09. 09. 2021

   @brief Solving task #1 for the course "Professional Programming"


*/




int main()
{
    UnitTest();
    printf("\tKozhanov Gleb, B05-120\n");
    printf("\tThe square equation solver\n\n");
    printf("PLease, enter a,b,c:");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    scanf("%lg %lg %lg", &a, &b, &c);
    int Nroot = SolvingEquation(a,b,c,&x1,&x2);

    switch (Nroot)
    {
        case 0: printf("No roots\n");
                break;

        case 1: printf("x1=%lg\n",x1);
                break;

        case 2: printf("x1=%lg, x2=%lg\n", x1, x2);
                break;

        case INFINITE_NROOTS: printf("Any number");
                break;

        default: printf("main(): ERROR: nRoots = %d/n", Nroot);
                return 1;

    }


    return 0;
}
