#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[18];

void ct(){
	for (int i = 0; i < n; i++)
		a[i] = 0;
	
	while(1){
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) cnt++;
		}
		if (cnt == k) {
			for (int i = 0; i < n; i++) 
				cout << a[i];
			cout << endl;
		}
		
		int i = n - 1;
		while(i >= 0 && a[i] == 1){
			a[i] = 0;
			i--;
		}
		if (i < 0) {
			return;
		}
		else {
			a[i] = 1;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		ct();
	}
}
