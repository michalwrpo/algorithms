#include <stdlib.h>

#include "binadd.h"

char* binaryAddition(char* num1, char* num2, int len) {
    char* ans = malloc((unsigned long)(len + 1) * sizeof(char));
    char carry = 0;
    char sum = 0;

    for (int i = len - 1; i > -1; i--) {
        if (num1[i] != 0 && num1[i] != 1) {
            free(ans);
            return NULL;
        }
        
        if (num2[i] != 0 && num2[i] != 1) {
            free(ans);
            return NULL;
        }
        
        sum = num1[i] + num2[i] + carry;
        carry = sum >> 1;
        ans[i + 1] = sum & 1;
    }

    ans[0] = carry;
    
    return ans;
}
