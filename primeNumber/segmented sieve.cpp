//Find prime Numbers in a segment [a,b]
//where 1<=a,b<=10^14 and 1<=(b-a)<=10^6
#include <bits//stdc++.h>
using namespace std;
#define NN 10000100
#define ll long long
bool pri[10000010] = {0};
vector <ll> prime;

void simpleSieve(ll limit) { //0 for prime
    for (ll i = 2; i <= limit; i++) {
        if (pri[i] == 0)
            for (ll j = i+i; j <= limit; j += i) pri[j] = 1;
    }
    for (ll i = 2; i <= limit; i++)
        if (pri[i] == 0) prime.push_back (i);
}
void segmentSieve (ll fno, ll sno) {
    bool mark[1000010] = {0};
    ll limit = sqrt (sno) + 1;
    for (ll i = 0; prime[i] < limit; i++) {
        ll loLimit = floor (fno /prime[i]) * prime[i];
        if (loLimit < fno) loLimit += prime[i];

        for (ll j = loLimit; j <= sno; j += prime[i]) {
            mark[j - fno] = 1; //not prime
        }
    }
    for (ll i = 0; i <=  sno-fno; i++) {
        if (mark[i] == 0) {
            cout << fno + i << " ";
        }
    }
    cout << "\n";
}
int main ()
{
//  ios::sync_with_stdio(0); cin.tie(0);
//  freopen ("in.txt", "r", stdin);
//  freopen ("out.txt", "w", stdout);
    ll highlimit = 1e14, hi, lo;
    simpleSieve (sqrt (highlimit) + 1);

    int tc, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> lo >> hi;
        segmentSieve (lo, hi);
    }

    return 0;
}
