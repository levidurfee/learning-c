#include <stdio.h>

int main() {
    int grades[3];
    int avg;

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    avg = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average is %d\r\n", avg);
    return 0;
}
