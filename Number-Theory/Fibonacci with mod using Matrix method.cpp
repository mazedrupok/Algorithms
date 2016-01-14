/* Fibonacci number using Matrix Method..
   | Fn | = |1  1|^n-1 *| 1 |
   |Fn-1|   |1  0|      | 1 |
   where Fn is the nth Fibonacci number..
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003
int ara[2][2] = {1,1,1,0};
long long tem[2][2] = {1,1,1,0};
void matrix_bigmod (int b) {
   if (b == 1) return;
   matrix_bigmod (b/2);
   long long temp[2][2] = {0};
   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
         long long sum = 0;
         for (int k = 0; k < 2; k++)
            sum += (tem[i][k] * tem[k][j]) %MOD;
         temp[i][j] = sum%MOD;
      }
   }
   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
         tem[i][j] = temp[i][j];
      }
   }
   if (b %2 == 1) {
      for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 2; j++) {
            long long sum = 0;
            for (int k = 0; k < 2; k++)
               sum += (temp[i][k] * ara[k][j]) %MOD;
            tem[i][j] = sum %MOD;
         }
      }
   }

}
int main ()
{
   int n;
   while (scanf (" %d", &n) == 1) {
      if (n == 1 || n == 0) {printf ("1\n"); continue;}
      matrix_bigmod (n-1);
      printf ("%lld\n", (tem[0][0]+tem[0][1]) %MOD);
      tem[0][0] = 1;
      tem[0][1] = 1;
      tem[1][0] = 1;
      tem[1][1] = 0;
   }
   return 0;
}
