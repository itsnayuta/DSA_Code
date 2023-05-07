#include <bits/stdc++.h>
using namespace std;
int check(int a[], int n) {
	int l = 0, r = n - 1;
	while(l < r){
		if (a[l] != a[r]) return 0;
		l++;
		r--;
	}
	return 1;
}

void ct(int n, int a[]) {
	while(1){
		if (check(a, n) == 1) {
			for (int t = 0; t < n; t++) cout << a[t] << " ";
			cout << endl; 
		}
		
		int i = n - 1;
		while(i >= 0 && a[i] == 1){
			a[i] = 0;
			i--;
		}
		if (i == -1) return;
		else a[i] = 1;
	}
}
int main(){
	int n; cin >> n;
	int a[n + 3];
	memset(a, 0, sizeof(a));
	ct(n, a);
}
