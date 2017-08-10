#include <bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define prr pair<pr, int>
#define ff first
#define ss second
#define MX 100005
using namespace std;
prr L[MX], tem[MX];
int p[33][MX];
int two[70];
string s;
void cnt_arr_sort(prr t[]) {
    int cnt_arr[MX];
    int N = s.size();
    prr temp[N + 9];
    memset(cnt_arr, 0, sizeof cnt_arr);
    for(int i = 0; i < N; i++)
        cnt_arr[t[i].ff.ss + 1]++; //process with rank2
    for(int i = 1; i < MX; i++)
        cnt_arr[i] += cnt_arr[i-1];
    for(int i = 0; i < N; i++) {
        temp[cnt_arr[t[i].ff.ss +1] - 1] = t[i];
        cnt_arr[t[i].ff.ss + 1]--;
    }
    memset(cnt_arr, 0, sizeof cnt_arr);
    for(int i = 0; i < N; i++)
        cnt_arr[t[i].ff.ff+ 1]++;  //process with rank1
    for(int i = 1; i < MX; i++)
        cnt_arr[i] += cnt_arr[i-1];
    for(int i = N-1; i >= 0; i--) {
        t[cnt_arr[temp[i].ff.ff+ 1] - 1] = temp[i];
        cnt_arr[temp[i].ff.ff+ 1]--;
    }
}
void suffix_array () { //O(n log n)
    int len = s.size();
    for (int i = 0; i < len; i++) p[0][i] = s[i] - 'a'; //for small cases
    int stp = 1;
    two[0] = 1;
    for (int i = 1; ; i++) {
        two[i] = two[i-1] * 2;
        if (two[i] > MX) break;
    }
    for (int stp = 1, cnt = 1; cnt >> 1 < len; stp++, cnt <<= 1) {
        for (int i = 0; i < len; i++) {
            L[i].ff.ff = p[stp-1][i];    //rank1
            L[i].ff.ss = i+cnt < len ? p[stp-1][i+cnt] : -1; //rank2
            //L[i].ff.ss = p[stp-1][(i+cnt) %len]; //spoj minmove
            L[i].ss = i;
        }
        //sort (L, L+len); //O(n log n)
        cnt_arr_sort (L);  //O(n)
        for (int i = 0; i < len; i++) {
            if (i > 0 && L[i].ff.ff == L[i-1].ff.ff && L[i].ff.ss == L[i-1].ff.ss) p[stp][L[i].ss] = p[stp][L[i-1].ss];
            else p[stp][L[i].ss] = i;
        }
    }
    printf ("Suffix array: ");
    for (int i = 0; i < len; i++) { //print ssition of suffix array
        cout << L[i].ss << " ";
    } cout << endl;
}
int LCP (int i, int j) {
    int ans = 0;
    int len = s.size();
    if (i == j) return len - i;
    int step = ceil(log(len)/log(2));
    for (step; step >= 0 && i < len && j < len; step--) {
        if (p[step][i] == p[step][j]) {
            ans += two[step]; //power of two
            i += two[step];
            j += two[step];
        }
    }
    return ans;
}
int main()
{
    while (cin >> s) {
        suffix_array ();
    }
    return 0;
}
