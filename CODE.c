#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "header.h"

int main(void) {
    codeLet *legend = generateLegend("CODE.INP.txt");

    findPossibilities(legend);

    free(legend);

    return 0;
}
