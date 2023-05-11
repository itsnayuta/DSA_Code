#include <bits/stdc++.h>
using namespace std;
// cai tui
int f[1001][1001];
int main(){
	int t; cin >> t;
	while(t--){
		int v, n; cin >> n >> v;
		int a[n + 1], c[n + 1];
		for (int i = 1;  i <= n; i++) cin >> a[i];
		for (int i = 1;  i <= n; i++) cin >> c[i];
		
		memset(f, 0, sizeof(f));
	
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= v; j++){
				f[i][j] = f[i-1][j];
				if(j >= a[i]){
					f[i][j] = max(f[i][j], f[i-1][j-a[i]] + c[i]);
				}
			}
		}
		cout << f[n][v] << endl;
	}
}