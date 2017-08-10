#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ff first
#define ss second
using namespace std;
int pi[1000001];
void prefix_function (string pattern) { //KMP
    int i = 1, j = 0;
    pi[j] = 0;
    for (i, j; i < pattern.size(); ) {
        if (pattern[i] == pattern[j]) {
            pi[i] = j+1;
            i++; j++;
        }
        else {
            while (pattern[i] != pattern[j] && j > 0) j = pi[j-1];
            if (pattern[i] != pattern[j]) {
                pi[i] = 0;
                i++;
            }
        }
    }
}
int kmp (string target, string pattern) {
    prefix_function (pattern);
    int i = 0, j = 0;
    int cnt = 0;
    //counting maximum suffix of target
    //which is also prefix in pattern
    for (i, j; i < target.size(); ) {
        if (target[i] == pattern[j]) {
            i++; j++;
        }
        else {
            while (target[i] != pattern[j] && j > 0) j = pi[j-1];
            if (target[i] != pattern[j]) i++;
        }
        if (j == pattern.size()) {
            cout << "Found at: " << i << endl;
            j = pi[j-1];
        }
    }
    return j;
}
int main()
{
    int tc, cs = 0, len;
    string s, t;
    while (cin >> s >> t) {
        int pos = kmp (s, t);
    }
    return 0;
}
