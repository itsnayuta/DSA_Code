#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n + 2];
	int f[n + 2];
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
		}
	}
	cout << *max_element(f, f + n + 1) + 1;
}
