#include <stdio.h>
#include <stdlib.h>
#include <assert.h>      // для assert
#include <math.h>       // для isfinite

#include "defines.h"
#include "unittest.h"

/**
    The Squire Equation SOlving function
    @param [in] a  a-coefficient
    @param [in] b  b-coefficient
    @param [in] c  c-coefficient
    @param [out] x1 x1-root
    @param [out] x2 x2-root
    @return Number of roots
*/

int SolvingEquation(double a, double b, double c, double* x1,double* x2){

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    if (IsZero(a,0) || (a<0.00001 && a>(-0.00001) ))
    {
        if (IsZero(b,0))
          {

          if (IsZero(c,0))
            {
            return INFINITE_NROOTS;
            }
          else
            {
            return 0;
            }

          }

        else
          {
          *x1=-c/b;
          return 1;
          }

    }

    else
        {
        double discr= b*b-4*a*c;


        if (discr<0)            // NEGATIVE DISCRIMINANT
            {
            return 0;
            }

        if (IsZero(discr,0))           // ZERO DISCRIMINANT
            {
            *x1=(-b)/(2*a);
            return 1;
            }

        if (discr>0)            // POSITIVE DISCRIMINANT
            {
            double dsqrt = sqrt(discr);

            *x1 = (-b-dsqrt) / (2*a);
            *x2 = (-b+dsqrt) / (2*a);

            return 2;
            }
        }

}
