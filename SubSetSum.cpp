#include <bits/stdc++.h>

using namespace std;
bool arr[101][100001];
int ar[101];

int n, m, maxn = -9999999, maxm = -9999999;

void MakeSol(){
    for(int j = 1; j <= maxm; j++) arr[0][j] = false;
    for(int i = 0; i <= maxn; i++) arr[i][0] = true;
    for(int i = 1; i <= maxn; i++){
        for(int j = 1; j <= maxm; j++){
            if(ar[i - 1] > j) arr[i][j] = arr[i-1][j];
            else arr[i][j] = arr[i-1][j] || arr[i-1][j-ar[i-1]];
        }
    }
}

int main(){
	int t; cin >> t;
	for(int k = 0; k < t; k++){
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> ar[i];
		vector<pair<int, int> > Q;
		for(int i = 0; i < m; i++){
			int x, k; cin >> x >> k;
			maxn = max(maxn, x);
			maxm = max(maxm, k);
			Q.push_back(make_pair(x, k));
		}
		MakeSol();
		cout << "caso " << k+1 << ": ";
		for(int i = 0; i < m; i++){
			cout << arr[Q[i].first][Q[i].second] << " ";
		}
		cout << endl;
	}
	return 0;
}
