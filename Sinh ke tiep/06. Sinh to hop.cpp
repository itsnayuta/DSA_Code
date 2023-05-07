#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100000];

void ct(){
	for (int i = 1; i <= k; i++) 
		a[i] = i;
	while(1){
		for (int i = 1; i <= k; i++)
			cout << a[i];
		cout << " ";
		
		int i = k;
		while(i > 0 && a[i] == n - k + i)
			i--;
		if (i == 0) {
			cout << endl;
			return;
		}
		
		a[i]++;
		for (int j = i + 1; j <= n; j++)
			a[j] = a[i] - i + j;
	}
}
int main(){
	int t; cin>> t;
	while(t--){
		cin >> n >> k;
		ct();
	}
}
