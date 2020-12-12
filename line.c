#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    int lstart = 0, lend = 0;
    if (argc == 2) {
        lstart = atoi(argv[1]);
        lend = lstart + 1;
    }
    else if (argc == 3) {
        lstart = atoi(argv[1]);
        lend = atoi(argv[2]);
    }
    else {
        printf("Usage %s <line_start> [line_end]\n", argv[0]);
        return 1;
    }
    if (lstart < 1 || lstart > lend) {
        printf("Error. line_start must be >=1 and less than line_end.");
        return 1;
    }
    size_t linecap = 1024*1024;
    char* line = malloc(linecap);
    size_t linelen;
    for(int i=0; i<lstart; i++){
        linelen = getline(&line, &linecap, stdin);
        if (linelen == -1) return 1;
    }
    for (int i=lstart; i<lend; i++) {
        fwrite(line, linelen, 1, stdout);
        linelen = getline(&line, &linecap, stdin);
        if (linelen == -1) return 1;
    }
    return 0;
}
