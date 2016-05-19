/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Stable marriage problem
   Comment:  lightoj 1040

*/
#include <bits/stdc++.h>
using namespace std;
int n; int prefer[210][110]; //as highest n is 100
bool wPreferM_M1 (int w, int m, int m1) {
   for (int k = 0; k < n; k++) {
      if (prefer[w][k] == m) return true;
      if (prefer[w][k] == m1) return false;
   }
}
void stableMarriage () {
   int wPartnr[n];
   bool freeMan[n];
   memset (wPartnr, -1, sizeof (wPartnr));
   memset (freeMan, 0, sizeof (freeMan));
   int freeCount = n;
   while (freeCount > 0) {
      int m;
      for (m = 0; m < n; m++)
         if (freeMan[m] == false) break;
      for (int i = 0; i < n && freeMan[m] == false; i++) {
         int w = prefer[m][i];
         if (wPartnr[w-n] == -1) { //w engaged with no one.
            wPartnr[w-n] = m;
            freeMan[m] = true;
            freeCount--;
         }
         else {
            int m1 = wPartnr[w-n]; //previous one, w engaged with m1.
            if (wPreferM_M1 (w, m, m1) == true) { //if m prefer for w.
               wPartnr[w-n] = m;
               freeMan[m] = true;
               freeMan[m1] = false;
            }
         }
      }
   }
   for (int i = 0; i < n; i++) {
      printf (" (%d %d)", wPartnr[i]+1, n+i+1);
   } printf ("\n");
}
int main ()
{
   int tc, cs = 0;
   //freopen ("in.txt", "r", stdin);
   cin >> tc;
   while (tc--) {
      cin >> n;
      for (int i = 0; i < 2*n; i++)
         for (int j = 0; j < n; j++) {
            cin >> prefer[i][j];
            prefer[i][j]--;
         }
      printf ("Case %d:", ++cs);
      stableMarriage();
   }
   return 0;
}
