
#include <bits/stdc++.h>
using namespace std;

void ct(string s) {
	int n = s.size();
	stack<string> st;
	for (int i = n - 1; i >= 0; i--) {
		string tmp = "";
		tmp += s[i];
		if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') {
			string x = st.top();
			st.pop();
			string y = st.top();
			st.pop();
			string z = "(" + x + tmp + y + ")";
			st.push(z);
		}
		else {
			st.push(tmp);
		}

	}
	cout << st.top();
}
int main() {
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		ct(s);
		cout << endl;
	}
}

