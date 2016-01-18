#include <stdio.h>
int i = 0, j = 0;
void TowerOfHanoi (int disks, char* Left, char* Mid, char* Right ) {

    if (disks != 0 ) {
        //printf ("%d:: %s %s %s\n", i++, Left, Mid, Right);
        //call recursively..
        TowerOfHanoi(disks-1, Left, Right, Mid);
        printf ("\n%d: Move disk: %d from %s to %s\n", ++j, disks, Left, Right);
        TowerOfHanoi(disks-1, Mid, Left, Right);
    }
}
int main ()
{
    int disks;
    char* tower1 = "Left Tower ";
    char* tower2 = "Mid Tower  ";
    char* tower3 = "Right Tower";
    printf ("How many disks: ");
    scanf (" %d", &disks);
    printf ("Tower of Hanoi with disks: %d\n", disks);
    TowerOfHanoi(disks, tower1, tower2, tower3);
    return 0;
}
