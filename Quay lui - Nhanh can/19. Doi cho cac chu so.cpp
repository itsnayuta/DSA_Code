#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

void ct(int k, string s){
	for (int i = 0; i < n - 1; i++){
		if (k == 0) break;
		
		char c = '0';
		for (int j = i + 1; j < n; j++){
			c = max(c, s[j]);
		}
		if (c <= s[i]) continue;
		string res;
		for (int j = i + 1; j < n; j++){
			if (c == s[j]){
				string s2 = s;
				swap(s2[i], s2[j]);
				res = max(s2, s);
			}
		}
		s = res;
		k--;
	}
	cout << s << endl;
}
int main() {
	int t; cin >> t;
	while(t--){
		cin >> k;
		cin >> s;
		n = s.size();
		ct(k, s);
	}
}


