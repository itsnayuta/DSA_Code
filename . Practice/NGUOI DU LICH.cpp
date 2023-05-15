#include <bits/stdc++.h>
using namespace std;
int n;
int cmin = INT_MAX;
int ans = INT_MAX;
vector<vector<int>> c;
vector<int> vs;

void Try(int i, int sum, int cnt){
	if(sum + cmin * (n - cnt + 1) >= ans)
		return;
	if (cnt == n){
		sum += c[i][1];
		ans = min(sum, ans);
		return;
	}
	
	for (int j = 1; j <= n; j++){
		if (vs[j] == 0 && c[i][j] != 0){
			vs[j] = 1;
			Try(j, sum + c[i][j], cnt + 1);
			vs[j] = 0;
		}
	}
}
int main(){
	cin >> n;
	c.resize(n + 1, vector<int> (n + 1));
	vs.resize(n + 1, 0);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> c[i][j];
			cmin = min(cmin, c[i][j]);
		}
	}
	vs[1] = 1;
	Try(1, 0, 1);
	cout << ans;
}
