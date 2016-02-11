//http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include <iostream>
#include <vector>
using namespace std;
void LIS (int ara[], int n) {
   vector <int > v[10000];
   int j = -1;
   for (int i = 0; i < n; i++) {
      if (i == 0) v[++j].push_back (ara[i]); //initialize..
      else if (ara[i] > v[j][j]) { //Clone & extend..
         v[j+1] = v[j];
         v[++j].push_back (ara[i]);
      }
      else { //clone & delete its previous..
         int k = j;
         while (k > -1 && ara[i] < v[k][k]) k--;
         if(k == -1) {v[0][0] = ara[i]; continue;}
         if (ara[i] == v[k][k]) {continue;} //For strictly increasing sequence..
         v[k+1] = v[k];
         v[++k].push_back (ara[i]);
      }
   }
   for (int k = 0; k <= j; k++) {
   cout << "Longest common sequence is: ";
   for (int i = 0; i < v[k].size(); i++) cout << v[k][i] << " ";
   cout << endl;
   cout << "Size is: " << v[k].size() << endl << endl;
   }
}
int main ()
{
   int ara[] = {10, 22, 2, 9, 33, 21, 50, 41, 60, 80};
   //int ara[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int n = sizeof (ara) / 4;
   LIS (ara, n);

   return 0;
}
