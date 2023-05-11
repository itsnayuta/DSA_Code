#include <bits/stdc++.h>
using namespace std;

int main(){
	int s, n; cin >> s >> n;
	int f[s + 3], c[n + 3];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);
	
	memset(f, 0, sizeof(s));
	f[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = s; j >= c[i]; j--){
			if (f[j - c[i]] == 1) f[j] = 1;
		}
	}
	for (int i = s; i >= 0; i--) {
		if (f[i] == 1){
			cout << i;
			break;
		}
	}
}