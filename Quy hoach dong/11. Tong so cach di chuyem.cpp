#include<bits/stdc++.h>
using namespace std;
int Mod = 1e9+7;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<long long> v(n + 1, 0);
		
		long long tmp = 0;
		for(int i = 1; i <= k; i++){
			v[i] = tmp + 1;
			v[i] %= Mod;
			tmp += v[i];
			tmp %= Mod;
		}
		
		for(int i = k + 1; i <= n; i++){
			for(int j = 1; j <= k; j++){
				v[i] += v[i-j];
				v[i] %= Mod;
			}
		}
		
		cout << v[n] << endl;
	}
}

