#include<bits/stdc++.h>

using namespace std;

void ct(string s) {
	int n = s.size();
	stack<int> st;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '(') {
			st.push(s[i]);
			cnt1++;
		} 
		else {
			if ( !st.empty() && st.top() == '(') {
				st.pop();
				cnt1--;
			} 
			else {
				st.push(s[i]);
				cnt2++;
			}
		}
	}
	
	int res = cnt1 / 2 + cnt2 / 2;
	res += cnt1 % 2 + cnt2 % 2;
	
	cout << res;
}
int main() {
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		ct(s);
		cout << endl;
	}
}

