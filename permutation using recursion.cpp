#include <stdio.h>

char arr[20]; //input
int taken[20] = {0}; //visit
char r[20]; //temporary array
int len; //length of input

void permute (int pos) {
    if (pos == len) {
        r[pos] = '\0';
        printf ("%s\n", r);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (taken[i] == 0) {
            taken[i] = 1;
            r[pos] = arr[i];
            permute(pos+1);
            taken[i] = 0;
        }
    }
}
int main ()
{
    int i;
    scanf (" %s", arr);
    len = 0;
    for (i = 0; arr[i]; i++ ) len++;
    permute (0);
}
