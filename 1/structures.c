#include <stdio.h>

typedef struct {
    char * name;
    int age;
} person;

int main() {
    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.\r\n", john.name, john.age);
}
