#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
   int tc, k = 0, n, res;
   cin >> tc;
   while (tc--) {
      cin >> n;
      int a = 1, b = 2, c = 3;
      while (n > 0) {
         a = b;
         b = c;
         c = a+b;
         n -= (c - b - 1);
      }
      n += (c - b - 1);
      res = n + b;
      cout << res << endl;
   }
   return 0;
}
