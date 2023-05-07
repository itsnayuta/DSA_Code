#include<bits/stdc++.h>
using namespace std;

int n, sum, check;
int a[11][11];
vector<string> ans;

void ct(int i, int j, string s){
	if (i == n - 1 && j == n - 1){
		ans.push_back(s);
		return;
	}
	
	if (i > 0 && a[i - 1][j] == 1) {
		a[i][j] = 0;
		ct(i - 1, j, s + "U");
		a[i][j] = 1;
	}
	if (i < n - 1 && a[i + 1][j] == 1) {
		a[i][j] = 0;
		ct(i + 1, j, s + "D");
		a[i][j] = 1;
	}
	if (j > 0 && a[i][j - 1] == 1) {
		a[i][j] = 0;
		ct(i , j - 1, s + "L");
		a[i][j] = 1;
	}
	if (j < n - 1 && a[i][j + 1] == 1) {
		a[i][j] = 0;
		ct(i, j + 1, s + "R");
		a[i][j] = 1;
	}
}
int main() {
	int t; cin >> t;
	while(t--){
		cin >> n;
		ans.clear();
		check = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}		
		if (a[0][0] == 0 || a[n - 1][n - 1] == 0){
			check = 1;
		}
		else ct(0, 0, "");
		if (ans.empty()) check = 1;
		if (check == 0) {
			sort(ans.begin(), ans.end());
			for (auto x : ans){
				cout << x << " ";
			}
			cout << endl;
		}
		else cout << -1 << endl;
	}
}


