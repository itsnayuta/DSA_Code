#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		int m = a.size(), n = b.size();

		int f[m + 1][n + 1];
		int ans = 0;
		memset(f, 0, sizeof(f));

		for (int i = 1;  i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (a[i - 1] == b[j - 1]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else f[i][j] = max(f[i][ j - 1], f[i - 1][j]);

				ans = max(ans, f[i][j]);
			}
		}
		cout << ans << endl;
	}
}
