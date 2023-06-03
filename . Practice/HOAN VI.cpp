#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100];
vector<string> ans;
int gt(int n){
	if (n == 1){
		return 1;
	}
	else return n * gt(n - 1);
}
void ct(){
	while(1){
		string tmp = "";
		for (int i = 1; i <= n; i++){
			tmp += to_string(a[i]) + " ";
		}
		tmp.pop_back();
		ans.push_back(tmp);
		int i = n - 1;
		while(i > 0 && a[i] >= a[i + 1] )
			i--;
		if (i == 0) return;
		
		int h = n;
		while(a[h] <= a[i]) 
			h--;
		swap(a[i], a[h]);
		int l = i + 1, r = n;
		while(l < r){
			swap(a[l], a[r]);
			l++; r--;
		}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		a[i] = i;
	}
	ct();
	for (int i = m; i <= gt(n); i += m){
		cout << ans[i - 1] << endl;
	}
}
