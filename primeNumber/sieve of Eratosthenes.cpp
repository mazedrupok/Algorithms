#include <bits/stdc++.h>
using namespace std;
bool pri[10000001];
void sieveOfEratosthenes (int limit) { //works in 10^7
   pri[0] = 0; pri[1] = 0;                        //prime number generator.. start
   for (int i = 2; i <= limit; i++) {
      pri[i] = 1;
   }
   for (int i = 2; i <= sqrt(limit); i++) {
      if (pri[i] == 0) continue;
      for (int j = 2; i*j <= limit; j++) {
         pri[i*j] = 0;
      }
   }
}
int main ()
{
   int n, limit = 10000000;
   sieveOfEratosthenes(limit);
   while(1) {
        printf("\nEnter number: (press 0 to exit) ");
        scanf("%d", &n);
        if(n == 0) break;
        else if (n > limit) continue;
        else if (0 == pri[n]) printf("%d is not a prime number.\n", n);
        else printf("%d is a prime number.\n", n);
        printf("\n");
   }
   return 0;
}
