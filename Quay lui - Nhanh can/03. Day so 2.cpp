#include <bits/stdc++.h>
using namespace std;
int n;
int a[103];
vector<string> ans;

void ct(int i){
	string s = "[";
	for (int j = 0; j < n - i + 1; j++){
		s += to_string(a[j]) + " ";
	}
	s.pop_back();
	s += "]";
	ans.push_back(s); 
	
	if (i == n) return;
	
	for (int j = 0; j < n - i; j++){
		a[j] = a[j] + a[j + 1];
	}
	ct(i + 1);
}
int main(){
	int t; cin >> t;
	while(t--){
		ans.clear();
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ct(1);
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
