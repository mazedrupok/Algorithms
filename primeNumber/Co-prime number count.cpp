/*
 Co-prime number count of a number
 Totient(n) = n * (1 - 1/p) * (1 - 1/q) ...
*/
#include <bits//stdc++.h>
using namespace std;
#define NN 10000010
#define ll long long
int phi (int n) {
    int ret = n;
    int limit = sqrt (n) + 1;
    for (int i = 2; i <= limit; i++) {
        if (n %i == 0) {
            while (n %i == 0) n /= i;
            ret -= (ret /i);
        }
    }
    if (n > 1) ret -= (ret /n);
    return ret;
}
int main ()
{
    int tc, cs = 0, num;
    cin >> tc;
    while (tc--) {
        cin >> num;
        cout << phi(num) << "\n";
    }
    return 0;
}
