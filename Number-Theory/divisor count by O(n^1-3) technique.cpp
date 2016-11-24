/*
Lightoj 1028, Tailing Zeros (i)
Counting divisors using N^(1/3) technique
http://codeforces.com/blog/entry/22317
*/
#include <bits//stdc++.h>
using namespace std;
#define NN 1000001 //sqrt(10^12)
#define ll long long
#define pb push_back
ll prime[NN+1], primeSize;
bool pri[NN+1] = {0}; //0 for prime
/////////////////////////////////////////////////////////////////////////
template <class T> inline T bigmod(T p,T e,T M){ //p^e %M
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
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
        x = (x * x) % n; //b1 = (b0 ^2) %n
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
//////////////////////////////////////////////////////////////////////////
void gene_prime() { //sieve
    pri[0] = 1; pri[1] = 1;
    for (int i = 2; i <= NN; i++) {
        if (pri[i] == 0) {
            for (int j = i+i; j <= NN; j += i) {
                pri[j] = 1;
            }
        }
    }
    primeSize = 0;
    for (int i = 2; i <= NN; i++) {
        if (pri[i] == 0) prime[primeSize++] = (ll) i;
    }
}
int main ()
{
    gene_prime ();
    map <ll, int> primeSquare;
    for (int i = 0; i < primeSize; i++) //check if primeSquare
        primeSquare[(ll)prime[i] * (ll)prime[i]] = prime[i];
    int tc, cs = 0, res; ll n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld", &n);
        res = 1;
        for (int i = 0; i*i*i <= n && i < primeSize; i++) {
            if (n %prime[i] == 0) {
                int k = 0;
                while (n %prime[i] == 0) {
                    k++;
                    n /= prime[i];
                }
                res *= (k+1);
            }
        }
        if (isPrime(n) == 1) res *= 2;            //if prime
        else if (primeSquare[n] > 0) res *= 3;//if prime square
        else if (n > 1) res *= 4;             //if multiple of two primes

        printf ("Case %d: %d\n", ++cs, res-1);
    }
    return 0;
}
