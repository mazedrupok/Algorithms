#include <iostream>
using namespace std;
int sum[20];
int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
void build (int at, int L, int R) {
    if (L == R) {
        sum[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    sum[at] = sum[2*at] + sum[2*at+1];
}
void update (int at, int L, int R, int pos, int value) {
    if (at == pos) {
        sum[at] += value;
        return;
    }
    int mid = (L+R) /2;
    if (pos <= at) update (2*at, L, mid, pos, value);
    else update (2*at+1, mid+1, R, pos, value);
    sum[at] = sum[2*at] + sum[2*at+1];
}
int query (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) return sum[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return x+y;
}
int main ()
{

    build (1, 1, 8);
    for (int i = 0; i < 20; i++) cout << sum[i] << " ";
    cout << endl;
    update (1, 1, 8, 3, 4);
    for (int i = 0; i < 25; i++) cout << sum[i] << " ";
    cout << endl;
    cout << query (1, 1, 8, 2, 6) << endl;
    return 0;
}
