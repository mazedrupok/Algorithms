//lightoj 1140
#include <bits//stdc++.h>
using namespace std;
#define ll long long
vector <int> inp; //to store digits
int sz; //vc.size()
ll dp[12][12][2][2];
ll fun (int pos, int zeros, bool is_start, bool is_small) {
    if (pos == sz) return zeros;
    ll &ret = dp[pos][zeros][is_start][is_small];
    if (ret != -1LL) return ret;
    ll cnt = 0LL;
    if (is_start == 1) {      //1st digit can't be zero
        cnt = fun (pos+1, zeros+1, 1, is_small | 0 < inp[pos]);
    }
    int r = is_small ? 9 : inp[pos]; //previous digit is less or not
    for (int i = 1; i <= r; i++) {
        cnt += fun (pos+1, zeros, 1, is_small | i < inp[pos]);
    }
    if (!is_start) cnt += fun (pos+1, 0, 0, 1); //suppose is_start from here
    return ret = cnt;
}
ll fun1 (ll x) {
    if (x < 0) return 0;
    if (x <= 9) return 1;
    inp.clear();
    memset (dp, -1, sizeof (dp));
    while (x) {
        inp.push_back (x %10);
        x /= 10;
    }
    sz = inp.size();
    reverse (inp.begin(), inp.end());
    return fun (0, 0, 0, 0) + 1; //1 for value zero
}
int main ()
{
    ll l, r;
    int tc, cs = 0;
    memset (dp, -1, sizeof (dp));
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %lld", &l, &r);
        printf ("Case %d: %lld\n", ++cs, fun1 (r) - fun1 (l-1));
    }
    return 0;
}
