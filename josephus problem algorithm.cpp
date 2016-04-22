//lightoj 1179
#include <bits/stdc++.h>
using namespace std;
/*
recursive formula is: f(n, k) = (f(n-1, k) + k-1) %n + 1;

int josephus(int n, int k) {
  if (n == 1) return 1;
  else return (josephus(n - 1, k) + k-1) % n + 1;
}
*/
int josephus(int N, int k) {
   int m = 1, n = 1;
   while (n <= N) {
      m = (m + k-1) %n + 1;
      n++;
   }
   return m;
}

int main()
{
    int tc, cs = 0, k, n, res;

    scanf(" %d", &tc);
    while(tc--) {
        scanf(" %d %d", &n, &k);
        res = josephus (n, k);
        printf ("Case %d: %d\n", ++cs, res);
    }
    return 0;
}
