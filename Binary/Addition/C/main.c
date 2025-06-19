#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#include "binadd.h"

#define MAX_LENGTH 20

int main(int argc, char** argv) {    
    char ch;
    char num[MAX_LENGTH];
    long len, i = 0;
    unsigned char print = 1;

    if (argc > 1) {
        if (!strcmp(argv[1], "false"))
            print = 0;
    }
    

    while (read(STDIN_FILENO, &ch, 1) > 0 && ch != ' ' && ch != '\n' && i < MAX_LENGTH) {
        num[i] = ch;
        i++;
    }
    
    len = atol(num);
    
    if (len < 1) {
        fprintf(stderr, "Length should be a positive integer.\n");
        return -1;
    }
    
    char array1[len];
    char array2[len];
    
    i = 0;
    while (i < len) {
        if (read(STDIN_FILENO, &ch, 1) < 0) {
            fprintf(stderr, "Given number doesn't match the given length,\n");
            return -2;
        }

        if (ch == '0') {
            array1[i] = 0;
        } else if (ch == '1') {
            array1[i] = 1;
        } else {
            fprintf(stderr, "Given number is not binary.\n");
            return -2;
        }
        
        i++;
    }

    // ignore separator
    read(STDIN_FILENO, &ch, 1);

    i = 0;
    while (i < len) {
        if (read(STDIN_FILENO, &ch, 1) < 0) {
            fprintf(stderr, "Given number doesn't match the given length,\n");
            return -2;
        }

        if (ch == '0') {
            array2[i] = 0;
        } else if (ch == '1') {
            array2[i] = 1;
        } else {
            fprintf(stderr, "Given number is not binary.\n");
            return -2;
        }
        
        i++;
    }

    char* added = binaryAddition(array1, array2, len);

    if (print) {
        for (long i = 0; i < len + 1; i++) {
            printf("%d", added[i]);
        }
        printf("\n");
    }

    return 0;
}
