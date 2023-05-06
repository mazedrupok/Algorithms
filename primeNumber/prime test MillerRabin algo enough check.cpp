/*
https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
https://www.youtube.com/watch?v=qdylJqXCDGs
http://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
*/

// Solution tested with https://www.codechef.com/problems/CHKPRM

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

template <class T> inline T bigmod(T p,T e,T M){ //p^e %M
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = ((__int128) ret * p) % M;
        p = ((__int128) p * p) % M;
    } return (T)ret;
}
vector <ll> v;
void generateValue () {
//https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
//enough to check with these numbers
    v.pb(2);  v.pb(3);  v.pb(5);  v.pb(7);
    v.pb(11); v.pb(13); v.pb(17); v.pb(19);
    v.pb(23); v.pb(29); v.pb(31); v.pb(37);
    v.pb(41); v.pb(61); v.pb(73); v.pb(1662803);
}
bool miillerTest(ll a, ll m, ll n) {
    ll x = bigmod(a, m, n); // Compute, b0 = a^m % n
    if (x == 1  || x == n-1) return true; //probably prime
    while (m != n-1) {
        x = ((__int128) x * x) % n; //b1 = (b0 ^2) %n
        m *= 2;          //iteration
        if (x == 1)      return false; //composite
        if (x == n-1)    return true; //probably prime
    }
    return false; //composite
}
bool isPrime(ll n) {
    //n-1 = 2^k * m; finding m
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    ll m = n - 1;
    while (m % 2 == 0) m /= 2;
    for (ll i = 0; i < v.size(); i++) {
         if (v[i] >= n-1) break;
         if (miillerTest(v[i], m, n) == false)
              return false; //composite
    }
    return true; //probably prime
}
int main()
{
    // freopen ("out2.txt", "w", stdout);
    generateValue();
    ll n;
    cin >> n;
    if(isPrime(n)) cout << "YES";
    else cout << "NO";

    return 0;
}
