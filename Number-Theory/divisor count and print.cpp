//divisor count and printing them
//lightoj 1014
#include <bits//stdc++.h>
using namespace std;
#define NN 100000
 
int prime[100010], primeSize;
bool pri[100010] = {0};
int cc[500000] = {0};
void gene_prime() {
    for (int i = 4; i <= NN; i += 2) {
        pri[i] = 1;
    }
    for (int i = 3; i <= NN; i += 2) {
        if (pri[i] == 0) {
            for (int j = i+i; j <= NN; j += i) {
                pri[j] = 1;
            }
        }
    }
    primeSize = 0;
    prime[primeSize++] = 1;
    for (int i = 2; i <= NN; i++) {
        if (pri[i] == 0) prime[primeSize++] = i;
    }
}
int main ()
{
  //ios::sync_with_stdio(0); cin.tie(0);
// freopen ("in.txt", "r", stdin);
//  freopen ("out.txt", "w", stdout);
//    clock_t start;
//    double duration;
//    start = clock();
 
    gene_prime ();
    int tc, cs = 0, P, L, n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &P, &L);
        n = P-L;
        int limit = sqrt (n);
 
        int ccSize = 0;
        map <int, int> mp;
 
        for (int i = 0; i < primeSize; i++) {
            if (prime[i] > limit) break;
            if (n %prime[i] == 0) {
                int j = prime[i];
                if (n %j != 0) break;
                if (mp.find(j) == mp.end()) {
                    mp[j] = 1; mp[n/j] = 1;
                    cc[ccSize++] = j;
                    if (j != n/j) cc[ccSize++] = n/j;
                }
            }
        }
 
        for (int i = 0; i < ccSize; i++) {
            for (int j = 0; j < ccSize; j++) {
                int temp = cc[i]*cc[j];
                if (temp > n || temp <= 0) continue;
                if (n %temp == 0 && mp.find(temp) == mp.end()) {
                    mp[temp] = 1; mp[n/temp] = 1;
                    cc[ccSize++] = temp;
                    if (temp != n/temp) cc[ccSize++] = n/temp;
                }
            }
        }
        sort (cc, cc+ccSize);
//        for (int i = 0; i < ccSize; i++) {
//            cout << cc[i] << " ";
//        } cout << endl;
        printf ("Case %d:", ++cs);
        int test = 0;
        for (int i = 0; i < ccSize; i++) {
            if (P %cc[i] == L) {
                test = 1;
                printf (" %d", cc[i]);
            }
        }
        if (test == 0) printf (" impossible");
        printf ("\n");
    }
//        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
//        cout<<"Time: "<< duration <<'\n';
    return 0;
}
 
