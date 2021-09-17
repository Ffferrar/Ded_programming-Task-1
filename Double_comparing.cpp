#include <stdio.h>
#include <stdlib.h>
#include "unittest.h"
#include <math.h>
#include "defines.h"

int IsZero(double x, double y){
        return  (fabs(x-y)<EPS);
}


