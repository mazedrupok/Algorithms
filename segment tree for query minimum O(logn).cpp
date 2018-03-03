//https://www.youtube.com/watch?v=ZBHKZF5w4YU 
#include <iostream>
#include <cstring>
using namespace std;
int mnm[20];
int num[] = {0, -1, 3, 4, 0, 2, 1, 2, 6};
void build (int at, int L, int R) { //build array in O(log2n) ..
    if (L == R) {
        mnm[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
}
void update (int at, int L, int R, int pos, int value) { //update by O(logn)..
    if (L == R) {
        mnm[at] = value;
        return;
    }
    int mid = (L+R) /2;
    if (pos <= mid) update (2*at, L, mid, pos, value);
    else update (2*at+1, mid+1, R, pos, value);
    mnm[at] = min(mnm[2*at], mnm[2*at+1]);
}
int query (int at, int L, int R, int l, int r) { ////search in range [1,5].. in O(logn)
    if (L > r || R < l) return 1e9;
    if (L >= l && R <= r) return mnm[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return min(x, y);
}
int main ()
{
    //memset (mnm, 1e9, sizeof (mnm)); //all indexing to maximum value..not necessary..
    build (1, 1, 8);        //building mnm array.. take memory 2n or 2(n+1)+1
    for (int i = 0; i < 20; i++) cout << mnm[i] << " ";
    cout << endl;
    cout << query (1, 1, 8, 1, 5) << endl;//search in range [1,5].. in O(logn)
    
    update (1, 1, 8, 3, -5); //update by O(logn)..
    for (int i = 0; i < 25; i++) cout << mnm[i] << " ";
    cout << endl;
    cout << query (1, 1, 8, 1, 8) << endl;
    return 0;
}
