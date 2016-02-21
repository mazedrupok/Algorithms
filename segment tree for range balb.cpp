//Lightoj 1080
#include <bits/stdc++.h>
using namespace std;
char s[100050];
int seg[400050];
void update (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        seg[at]++;
        return;
    }
    int mid = (L+R) /2;
    update (2*at, L, mid, l, r);
    update (2*at+1, mid+1, R, l, r);
}
void query (int at, int L, int R, int pos) {
    if (seg[at] != 0) {
        if (L != R) {
            seg[2*at] += seg[at];
            seg[2*at+1] += seg[at];
            seg[at] = 0;
        }
    }
    if (L > pos || R < pos) return;
    if (L == R) {
        if (seg[at] %2 == 1) {
            if (s[L] == '1') s[L] = '0';
            else s[L] = '1';
        }
        seg[at] = 0;
        return;
    }
    int mid = (L+R) /2;
    query (2*at, L, mid, pos);
    query (2*at+1, mid+1, R, pos);
}
int main()
{
    int tc, k = 0, q, a, b, pos; char ch;
    //freopen ("in.txt", "r", stdin);
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %s", s);
        int len = strlen(s);
        for (int i = 0; i < len*4; i++ ) seg[i] = 0;
        scanf (" %d", &q);
        printf ("Case %d:\n", ++k);
        while (q--) {
            scanf (" %c", &ch);
            if (ch == 'I') {
                scanf (" %d %d", &a, &b);
                update (1, 0, len-1, a-1, b-1);
            }
            else if (ch == 'Q') {
                scanf (" %d", &pos);
                query (1, 0, len-1, pos-1);
                printf ("%c\n", s[pos-1]);
            }
        }
    }
    return 0;
}
