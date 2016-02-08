#include <iostream>
#include <cstdio>
using namespace std;
int used[100], number[100], ara[100];
int cnt = 0;
void permute (int pos, int n, int r) {
   if (pos == r+1) {
      for (int i = 1; i <= r; i++) printf ("%d ", number[i]);
      printf ("\n");
      cnt++;
      return;
   }
   for (int i = 1; i <= n; i++) {
      if (used[i] == 0) {
         used[i] = 1;
         number[pos] = ara[i];
         permute (pos+1, n, r);
         used[i] = 0;
      }
   }
}
int main ()
{
   int n, r;
   scanf (" %d %d", &n, &r); //Enter n & r of nPr .. :)
   for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
   permute (1, n, r);
   printf ("count: %d\n", cnt);
   return 0;
}
