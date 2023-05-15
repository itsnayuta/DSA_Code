#include<bits/stdc++.h>
using namespace std;
int a[1003][1003];
int ans, check;
int n, m;
void ct(int i, int j, int cnt){
	if (i == n - 1 && j == m - 1){
		check = 0;
		ans = min(ans, cnt);
		return;
	}
	int k;
	
	k = abs(a[i][j] - a[i + 1][j]);
	ct(i + k, j, cnt + 1);
	
	k = abs(a[i][j] - a[i][j + 1]);
	ct(i, j + k, cnt + 1);
	
	k = abs(a[i][j] - a[i + 1][j + 1]);
	ct(i + k, j + k, cnt + 1);
}
int main(){
	int t; cin >> t;
	while(t--){
		ans = INT_MAX; check = 1;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		ct(0, 0, 0);
		if (check == 1){
			cout << -1 << endl;
		}
		else cout << ans << endl;
	}
}
