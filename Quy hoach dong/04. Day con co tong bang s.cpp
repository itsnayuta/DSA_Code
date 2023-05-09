#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, s; cin >> n >> s;
		int a[n + 1], f[s + 1];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 0; i < n; i++){
			for (int j = s; j >= a[0]; j--){
				if (f[j - a[i]] == 1) f[j] = 1;
			}
		}
		if (f[s] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
