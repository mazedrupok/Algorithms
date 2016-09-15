//Binary Indexed Tree, lightoj 1112
//Range query sum
#include <bits/stdc++.h>
using namespace std;
int tree[100010] = {0};
int ara[100010];
int query (int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int update (int idx, int x, int n) {
    while (idx <= n) {
        tree[idx] += x;
        idx += (idx & -idx);
    }
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int n, x, q, tc, cs = 0, L, R, t;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf (" %d", &ara[i]);
            update (i, ara[i], n);
        }
        //for (int i = 1; i <= n; i++) printf ("%d ", tree[i]); printf ("\n");

        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d %d", &t, &L); L++;
            if (t == 1) {
                printf ("%d\n", ara[L]);
                update (L, -ara[L], n);
                ara[L] = 0;
            }
            else if (t == 2) {
                scanf (" %d", &x);
                ara[L] += x;
                update (L, x, n);
            }
            else if (t == 3) {
                scanf (" %d", &R); R++;
                printf ("%d\n", query(R)-query(L-1));
            }
            //for (int i = 1; i <= n; i++) printf ("%d ", tree[i]); printf ("\n");
        }
        for (int i = 1; i <= n; i++) tree[i] = 0;
    }
    return 0;
}
