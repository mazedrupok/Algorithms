#include <iostream>
#include <vector>
using namespace std;
char arr[] = {'a', 'b', 'c', 'd', 'e'};
int taken[20] = {0};
vector <char > r;
void permute () {
   if (r.size() == 5) {
      for (int i = 0; i < 5; i++) cout << r[i] << " ";
      cout << endl;
      return;
   }
   for (int i = 0; i < 5; i++) {
      if (taken[i] == 0) {
         taken[i] = 1; r.push_back(arr[i]);
         permute();
         taken[i] = 0; r.pop_back();
      }
   }
}
int main ()
{
   permute ();
}
/*#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
   vector <int > v;
   for (int i = 1; i < 6; i++) v.push_back (i);
   int count = 0;
   while (next_permutation(v.begin(), v.end())) {
      for (int i = 0; i < 5; i++) cout << v[i] << " ";
      count++;
      cout << endl;
   }
   cout << count << endl;
}
*/
