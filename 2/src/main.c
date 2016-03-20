#include <stdio.h>
#include "main.h"
#include "levi.h"
#include "durfee.h"

#define VERSION 0.1.0

int main(int argc, char *argv[]) {
    int x;
    levi(argv[1]);

    point p;
    p.x = 5;
    p.y = 6;
    durfee(&p);

    for (x = 0; x < 10; x++) {
        printf("%i", x);
    }
    printf("\r\n");

    return 0;
}
