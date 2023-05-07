#include <bits/stdc++.h>
using namespace std;
int n;
char v;
int a[30], c[30];

void ct(int i){
	if (i > n){
		for (int j = 1; j <= n; j++){
			if (a[j] == 0) return;
			if (abs(a[j - 1] - a[j]) == 1) return;
		}
		for (int j = 1; j <= n; j++){
				cout << a[j];
		}
		cout << endl;
		return;
	}
	for (int j = 1; j <= n; j++){
		if (c[j] == 0){
			c[j] = 1;
			a[i] = j;
			ct(i + 1);
			c[j] = 0;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		memset(c, 0,sizeof(c));
		a[0] = n + 2;
		ct(1);
	}
	
}
