// DOAN LIEN TIEP
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		vector<int> f(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		for (int i = 0; i <n; i++){
			int tmp = 1;
			for (int j = i - 1; j >= 0; j--){
				if (a[j] <= a[i]){
					tmp++;
				}
				else break;
			}
			f[i] = tmp;
		}
		
		for (auto x: f){
			cout << x << " ";
		}
		cout << endl;
	}
}
