#include <bits/stdc++.h>
using namespace std;
string s;
int n, check;

void ct(){
	stack<char> st;
	
	for (int i = 0; i < n; i++){
		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
			st.push(s[i]);
		else {
			if (st.empty()) {
				cout << "NO" << endl;
				return;
			}
			char c = st.top();
			if (c == '[' && s[i] == ']') st.pop();
			else if (c == '(' && s[i] == ')') st.pop();
			else if (c == '{' && s[i] == '}') st.pop();
			else {
				cout << "NO" << endl;
				return;
			}
		}
	}
	if (st.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		check = 0;
		ct();
	}
}
