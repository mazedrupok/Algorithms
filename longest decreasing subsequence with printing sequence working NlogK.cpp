//implementation of jane alam jans document about LIS in O(NlogK)
#include <iostream>
#include <cstdio>
using namespace std;
int bsearch (int a[], int l, int r, int d) {
   int m;
   while (l < r) {
      m = (l+r) /2;
      if (d == a[m]) return m;
      else if (d > a[m]) r = m; // < for increasing..
      else l = m;
      if (l == r-1) break;
   }
   return r;
}
int main ()
{
   int a[] = {8, 1, 9, 8, 3, 4 , 6, 1, 5, 2};
   int n = sizeof (a) /4;
   int T[n+1], L[n];
   T[0] =  1e9; //T[0] negative infinity
   for (int i = 1; i <= n; i++) T[i] = -1* 1e9; //all value in T to infinity..
   for (int i = 0; i <= n; i++) L[i] = 1;  //all value in L to 1
   int j = 1; T[1] = a[0];
   for (int i = 0; i < n; i++) {
      if (a[i] >= T[j]) {  //< for increasing..
         int k = j;
//         while (a[i] <= T[--k]) ;
         k = bsearch (T, 0, k+1, a[i]); //complexity nlog(K) :)
         T[k] = a[i];
         L[i] = k;
      }
      else {
         T[++j] = a[i];
         L[i] = j;
      }
   }
//   for (int i = 0; i < n; i++) cout << L[i] << " ";
//   cout << endl;
//   for (int i = 1; i < n; i++) cout << T[i] << " ";
//   cout << endl;
   cout << "Size: " << j << endl;
   int seq[j+1];
   for (int i = n-1, k = j; i >= 0; i--) {
      if (L[i] == k) {
         seq[k] = a[i];
         k--;
      }
   }
   for (int i = 1; i <= j; i++) cout << seq[i] << " ";
   cout << endl;
   return 0;
}
