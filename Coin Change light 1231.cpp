#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 100000007

int coin[55], times[55];
int n, make;
int dp[51][1001];
int coinChange (int i, int amount) {
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    if (i == n) return 0;

    if (dp[i][amount] != -1) return dp[i][amount];

    int v1 = 0, v2 = 0;
    for (int j = 1; j <= times[i]; j++) {
        if (amount - coin[i]*j >= 0)
            v1 += (coinChange (i+1, amount - coin[i]*j) %MOD);
        else break;
    }
    v2 = coinChange (i+1, amount) %MOD;

    return dp[i][amount] = (v1+v2) %MOD;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int tc, cs = 0, x;
	scanf (" %d", &tc);
	while (tc--) {
        scanf (" %d %d", &n, &make);
        for (int i = 0; i < n; i++) scanf (" %d", &coin[i]);
        for (int i = 0; i < n; i++) scanf (" %d", &times[i]);
        memset (dp, -1, sizeof (dp));
        int r = coinChange (0, make) %MOD;
        printf ("Case %d: %d\n", ++cs, r);
	}
    return 0;
}
