#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100000];

void ct(){
	int i = n - 1;
	while(i > 0 && a[i] >= a[i + 1]) 
		i--;
	if (i == 0){
		for (int j = 1; j <= n; j++)
			cout << j << " ";
		cout << endl;
		return;
	}
	else {
		int h = n;
		while(a[h] <= a[i]) 
			h--;
		swap(a[h], a[i]);
		int l = i + 1, r = n;
		while(l < r){
			swap(a[l], a[r]);
			l++; r--;
		}
		
		for (int j = 1; j <= n; j++)
			cout << a[j] << " ";
		cout << endl;
		return;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ct();	
	}
}
