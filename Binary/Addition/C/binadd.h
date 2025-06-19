#ifndef BINADD_H
#define BINADD_H

// takes 2 arrays representing binary numbers and adds them
// arrays should have matching length given to the function as len
// returns a pointer to a malloced array of length len + 1
char* binaryAddition(char* num1, char* num2, int len);

#endif