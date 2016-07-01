#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1005
#define sc(a) scanf(" %d", &a)
#define sc2(a,b) scanf(" %d %d", &a, &b)
#define for(a,b) for(int i = a; i <= b; i++)
#define forD(a,b) for(int i = a; i >= b; i--)
int coin[] = {1,5,10,25,50};
int n, make;
int dp[6][10000];
int coinChange (int i, int amount) {
    if (i == 5) {
        if (amount == 0) return 1;
        else return 0;
    }
    if (dp[i][amount] != -1) return dp[i][amount];
    int v1 = 0, v2 = 0;
    if (amount - coin[i] >= 0) v1 = coinChange (i, amount - coin[i]);
    v2 = coinChange (i+1, amount);

    return dp[i][amount] = v1+v2;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	memset (dp, -1, sizeof (dp));
    while (cin >> make) {
        cout << coinChange (0, make) << endl;
    }

    return 0;
}
