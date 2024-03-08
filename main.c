#include <stdio.h>
#include "cli.h"

int main()
{
    tPoint p = showCli();
    int result = count_points(&p);
    printf("Count: %i\n", result);
    return 0;
}