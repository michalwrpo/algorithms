#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#include "selectionsort.h"

#define MAX_LENGTH 20

int main(int argc, char** argv) {    
    char ch;
    char num[MAX_LENGTH];
    int len, i = 0;
    unsigned char j, print = 1;

    if (argc > 1) {
        if (!strcmp(argv[1], "false"))
            print = 0;
    }
    

    while (read(STDIN_FILENO, &ch, 1) > 0 && ch != ' ' && ch != '\n' && i < MAX_LENGTH) {
        num[i] = ch;
        i++;
    }
    
    len = atoi(num);
    
    if (len < 1) {
        fprintf(stderr, "Length should be a positive integer.\n");
        return -1;
    }
    
    int array[len];
    
    i = 0;
    while (i < len) {
        j = 0;
        do {
            if (read(STDIN_FILENO, &ch, 1) < 0) {
                fprintf(stderr, "Given array doesn't match the given length,\n");
                return -2;
            }
            num[j] = ch;
            j++;
        } while (ch != ' ' && ch != '\n' && j < MAX_LENGTH);
        num[j] = '\0';

        array[i] = atoi(num);
        i++;
    }

    selectionSort(array, len);

    if (print) {
        for (int i = 0; i < len; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
