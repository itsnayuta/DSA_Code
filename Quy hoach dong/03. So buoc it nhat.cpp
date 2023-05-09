#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = 0;
		int a[n + 1], f[n + 1];
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 1; i < n;i++){
			for (int j = 0; j < i; j++){
				if (a[j] <= a[i]) f[i] = max(f[i], f[j] + 1);
			}
			ans = max(ans, f[i]);
		}
		
		cout << n - ans - 1 << endl;
	}
}
