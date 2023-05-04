#include <bits/stdc++.h>
using namespace std;
int n;
int a[13][13];
vector<string> ans;

void ct(int i, int j, string s){
	if (i == n - 1 && j == n - 1) {
		ans.push_back(s);
	}
	
	if (i < n - 1 && a[i + 1][j] == 1) ct(i + 1, j, s + "D");
	if (j < n - 1 && a[i][j + 1] == 1) ct(i, j + 1, s + "R");
}
int main(){
	int t; cin >> t;
	while(t--){
		ans.clear();
		cin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		if (a[0][0] == 0 || a[n - 1][n - 1] == 0) {
			cout << -1 << endl;
		}
		else {
			ct(0, 0, "");
			if (ans.empty()) {
				cout << -1 << endl;
			}
			else {
				sort(ans.begin(), ans.end());
				for (auto x: ans) cout << x << " ";
				cout << endl;
			}
			
		}
	}
}

