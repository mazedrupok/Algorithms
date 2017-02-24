#include <bits/stdc++.h>
using namespace std;
int mark[1000010];
vector <int> divi[1000010];
void divisors (int n) {  // complexity: O(n) * 10 * (STL time taken)
   for (int i = 1; i <= n; i++)
      for (int j = i; j <= n; j += i)
         divi[j].push_back(i);

}
int main ()
{
   divisors(100000);  //1000000 takes 4 sec..
   int q, n;
   cin >> q;
   while (q--) {
      cin >> n;
      for (int i = 0; i < divi[n].size(); i++) {
         cout << divi[n][i] << " ";
      }
      cout << endl;
   }
}
