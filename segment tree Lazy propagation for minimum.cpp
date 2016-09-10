/*
    Md. Abdul Mazed
    Noakhali Science & Technology University (NSTU)
    mazed4g@gmail.com
    github.com/mazedrupok
*/
#include <bits/stdc++.h>
using namespace std;
int ara[100000];
int seg[400000];
int lazy[400000];
void build (int at, int L, int R) {
    if (L == R) {
        seg[at] = ara[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    seg[at] = min (seg[2*at], seg[2*at+1]);
}
void update (int at, int L, int R, int l, int r, int value) { //update from l to r
    if (lazy[at] != 0) { //if lazy[] contains previous value..
        seg[at] += lazy[at]; //update by lazy[] value..
        if(L != R) { //if not leaf node..
            lazy[2*at] += lazy[at]; //update child node..
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0; //after update make it zero..
    }
    if (L > r || R < l) return; //not overlap do nothing and return..
    if (L >= l && R <= r) { //totally overlap..
        seg[at] += value; //update range..
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
    seg[at] = min (seg[2*at], seg[2*at+1]);
}
int query (int at, int L, int R, int l, int r) { //query from l to r.. in O(logn)
    if (lazy[at] != 0) {
        seg[at] += lazy[at]; //update value from lazy[] value..
        if(L != R) { //if not leaf node..
            lazy[2*at] += lazy[at];
            lazy[2*at+1] += lazy[at];
        }
        lazy[at] = 0; //after update make it zero..
    }
    if (L > r || R < l) return 1e9; //not overlap return maximum..

    if (L >= l && R <= r) return seg[at]; //totally overlap return current value..
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return min(x, y);
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int n;
    scanf (" %d", &n);
    for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
    memset (lazy, 0, sizeof (lazy));
    build (1, 1, n);
    for (int i = 0; i <= 16; i++) cout << seg[i] << " "; cout << endl;
    update (1, 1, n, 8, 8, 3);
    for (int i = 0; i <= 16; i++) cout << seg[i] << " "; cout << endl;
    cout << query (1, 1, n, 8, 8) << endl;
    for (int i = 0; i <= 16; i++) cout << seg[i] << " "; cout << endl;

}
/*
segment tree lazy propagation
dynamic programming
https://www.youtube.com/watch?v=xuoQdt5pHj0
*/
