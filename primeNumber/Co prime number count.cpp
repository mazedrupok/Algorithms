/*
 Co-prime number of a number
 Totient(n) = n * (1 - 1/p) * (1 - 1/q) ...
 Off-line calculation in 10^7
*/
#include <bits//stdc++.h>
using namespace std;
#define NN 10000010
#define ll long long
int phi[10000010] = {0};
bool mark[10000010] = {0};
void EulerTotientValue (int limit) {
    for (int i = 1; i <= limit; i++) phi[i] = i;
    for (int i = 2; i <= limit; i++) {
        if (mark[i] == 0) {
            for (int j = i; j <= limit; j += i) {
                mark[j] = 1;
                phi[j] = phi[j] /i * (i-1);
            }
        }
    }
}
int main ()
{
    EulerTotientValue ((int) 1e7 );

    int tc, cs = 0, num;
    cin >> tc;
    while (tc--) {
        cin >> num;
        cout << phi[num] << "\n";
    }

    return 0;
}
