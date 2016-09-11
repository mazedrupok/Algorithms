/*
 lightoj 1164
 range update and range query for sum
*/
#include <bits//stdc++.h>
using namespace std;
#define LL long long
#define inf INT_MAX
const int sz = 100005;
int n;
LL seg[400010] = {0};
LL lazy[400010] = {0};
/*
void build (int at, int L, int R) {
    if (L == R) {
        seg[at] = ara[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    seg[at] = seg[2*at] + seg[2*at+1];
}
*/

void update (int at, int L, int R, int l, int r, int value) {
    if (lazy[at] != 0) { //if lazy[] contains previous value..
        seg[at] += (lazy[at] * (R-L+1) ); //update by lazy[] value..
        if(L != R) { //if not leaf node..
            lazy[2*at] += lazy[at]; //update child node..
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0; //after update make it zero..
    }
    if (L > r || R < l) return; //not overlap do nothing and return..
    if (L >= l && R <= r) { //totally overlap..
        seg[at] += (value * (R-L+1));  //update range..
        if (L != R) { //not leaf node..
            lazy[2*at] += value; //update child node..
            lazy[2*at+1] += value;
        }
        return;
    }
    //upper two condition false means partial overlap..
    int mid = (L+R) /2;
    update (2*at, L, mid, l, r, value);
    update (2*at+1, mid+1, R, l, r, value);
    seg[at] = seg[2*at] + seg[2*at+1];
}
LL query (int at, int L, int R, int l, int r) { //search in range [1,5].. in O(logn)
    if (lazy[at] != 0) {
        seg[at] += (lazy[at] * (R-L+1)); //update value from lazy[] value..
        if(L != R) { //if not leaf node..
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0; //after update make it zero..
    }
    if (L > r || R < l) return 0; //not overlap return maximum..

    if (L >= l && R <= r) return seg[at]; //totally overlap return current value..
    int mid = (L+R) /2;
    LL x = query (2*at, L, mid, l, r);
    LL y = query (2*at+1, mid+1, R, l, r);
    return (x + y);
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, q, x, y, v, t;
    LL res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        memset (seg, 0, sizeof (seg));
        memset (lazy, 0, sizeof (lazy));
        //build(1, 1, n);

        printf ("Case %d:\n", ++cs);
        while (q--) {
            scanf (" %d", &t);
            if (t == 0) {
                scanf (" %d %d %d", &x, &y, &v);
                x++; y++;
                update (1, 1, n, x, y, v);
            }
            else if (t == 1) {
                scanf (" %d %d", &x, &y);
                x++; y++;
                res = query(1, 1, n, x, y);
                printf ("%lld\n", res);
            }
        }
    }
    return 0;
}
