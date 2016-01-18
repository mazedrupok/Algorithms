#include <stdio.h>
int main ()
{
   int ara[] = {13,4,45,0,13,18,5,7,3,11};
   int n, i, j, t, m;
   n = sizeof(ara);
   n /= 4;
   printf("Size of the array: %d\n", n);
   printf ("Array element: ");
   for (i = 0; i < n; i++)  printf("%d ", ara[i]);
   printf ("\n");
         //Bubble Sort Start from here..
   m = n;
   for (j = 1; j < m; j++) {
      for (i = 0; i < m-1; i++) {
         if (ara[i] > ara[i+1] ) { //swarping
            t = ara[i];
            ara[i] = ara[i+1];
            ara[i+1] = t;
         }
      }
      m--;
   }
   printf("\nAfter Bubble sorting elements: ");
   for (i = 0; i < n; i++ )  printf("%d ", ara[i]);
   printf ("\n");

   return 0;
}
