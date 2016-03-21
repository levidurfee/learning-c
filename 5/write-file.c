#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/stat.h>

int fill_file(char *rdir);

int main(int argc, char **argv) {
    int i = 0;
    mkdir(argv[1], S_IRWXU);
    while(i < 10000000000) {
        fill_file(argv[1]);
        i++;
    }
    return 0;
}

int fill_file(char *rdir) {
    /*printf("%s\n", rdir);*/
    char file[50];
    char dir[50];
    struct timeb tmb;
    ftime(&tmb);

    time_t seconds;
    seconds = time(NULL);
    snprintf(dir, sizeof dir, "%s/%ld", rdir, seconds);
    mkdir(dir, S_IRWXU);
    printf("%ld-%d.txt\n", seconds, tmb.millitm);

    snprintf(file, sizeof file, "%s/%ld/%ld-%d.txt", rdir, seconds, seconds, tmb.millitm);
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
