#include <stdio.h>
#include <time.h>

int fill_file();

int main() {
    int i = 0;
    while(i < 10000000) {
        fill_file();
        i++;
    }
    return 0;
}

int fill_file() {
    char file[50];
    time_t seconds;
    seconds = time(NULL);
    printf("%ld.txt\n", seconds);

    snprintf(file, sizeof file, "txt/%ld.txt", seconds);
    FILE *f = fopen(file, "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    /* print some text */
    const char *text = "Write this to the file";
    fprintf(f, "Some text: %s\n", text);

    /* print integers and floats */
    int i = 1;
    float py = 3.1415927;
    fprintf(f, "Integer: %d, float: %f\n", i, py);

    /* printing single chatacters */
    char c = 'A';
    fprintf(f, "A character: %c\n", c);

    fclose(f);
    return 0;
}
