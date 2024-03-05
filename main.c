#include <stdio.h>
#include "point.h"
#include "cli.h"

int main()
{
    tPoint p = read();
    int result = count_points(&p);
    printf("%i\n", result);
    return 0;
}