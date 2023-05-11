#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		long long f[100009];
		memset(f, 0, sizeof(f));
		int tmp = 0;
		for (int i = 1; i <= k; i++){
			f[i] = tmp + 1;
			tmp %= mod;
			tmp += f[i];
			tmp %= mod;
		}
		for (int i = k + 1; i <= n; i++){
			for (int j = 1; j <= k; j++){
				f[i] += f[i - j];
				f[i] %= mod;
			}
		}

		cout << f[n] << endl;
	}
}
