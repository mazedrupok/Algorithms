/*
https://www.youtube.com/watch?v=qdylJqXCDGs
http://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <class T> inline T bigpow(T p,T e,T M){ //(p^e) %M
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
bool miillerTest(ll m, ll n) {
    ll a = 2 + rand() % (n - 4);
    ll x = bigpow(a, m, n);  //b0 = (a^m) %n;
    if (x == 1  || x == n-1)
       return true;
    while (m != n-1) {
        x = (x * x) % n; //b1 = (b0 ^2) %n
        m *= 2;          //2^k = n-1, checking iteration

        if (x == 1)      return false; //composite
        if (x == n-1)    return true; //probably prime
    }
    return false; //composite
}
bool isPrime(ll n, ll k) {
    // n-1 = (2^k) * m, 1st find m
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    ll m = n - 1;
    while (m % 2 == 0)
        m /= 2;
    for (ll i = 0; i < k; i++) //k times iteration
        if (miillerTest(m, n) == false)
              return false;
    return true;
}
int main()
{
    //freopen ("out3.txt", "w", stdout);
    ll k = 4;  // Number of iterations
    for (ll n = 1; n <= 1000001; n++)
       if (isPrime(n, k))
          cout << n << "\n";

    return 0;
}
