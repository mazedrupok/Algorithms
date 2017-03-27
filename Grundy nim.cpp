//https://www.codechef.com/problems/EXPGAME -> its solution
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int grun[MX] , rev[6] = { 1 , 4 , 27, 256, 3125, 46656}; // in a single move n*n can be removed
int fun (int x) {
    if( x == 0 ) return 0; // base case , grundy is always zero
    int &ret = grun[x];
    if( ret != -1 ) return ret;
    set <int> s;
    for (int i = 0;  i < 6; i++) {
        if(x - rev[i] >= 0) s.insert( fun(x-rev[i]) );
    }
    int ans = 0;
//    cout << endl <<"x: " << x << endl;
//    for (auto y : s) {
//        cout << y << " ";
//    } cout << endl;
    while(s.find(ans) != s.end()) ans++;
    //cout << ans << endl;
    return ret = ans;
}
int main()
{
  // ios_base::sync_with_stdio(0); cin.tie(0);
    memset (grun, -1, sizeof (grun));
    int cs, tc;
    scanf(" %d", &tc);
    while (tc--) {
        int n, i, ans = 0, x;
        scanf(" %d", &n);
        for ( i = 0; i < n; i++) {
            scanf("%d", &x);
            ans ^= fun(x);
        }
        if(ans) puts("Little Chef"); // first mover win
        else puts("Head Chef");
    }
    return 0;
}
