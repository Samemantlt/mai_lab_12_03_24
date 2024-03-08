#include <stdio.h>
#include "cli.h"

int main()
{
    tPoint p = showCli();
    int result = countPoints(&p);
    printf("\nCount: %i\n", result);
    return 0;
}