#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[13];
int v[13];
vector<string> ans;

void ct(int i){
	if (i == n + 1) {
		string tmp;
		for (int j = 1; j <= n; j++){
			tmp += s[a[j] - 1];
		}
		ans.push_back(tmp);
		return;
	}
	for (int j = 1; j <= n; j++){
		if (v[j] == 0){
			v[j] = 1;
			a[i] = j;
			ct(i + 1);
			v[j] = 0;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		ans.clear();
		memset(v, 0, sizeof(v));
		ct(1);
		for (auto x : ans){
			cout << x << " ";
		}
		cout << endl;
	}
}
