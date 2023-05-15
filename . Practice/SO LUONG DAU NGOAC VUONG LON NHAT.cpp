#include<bits/stdc++.h>
using namespace std;

void ct(string a) {
	stack<char> st;
	int n = a.size();
	for (int i = 0; i < n; i++){
		if (a[i] == '(' || a[i] == '[' ) {
			st.push(a[i]);
		}
		else {
			if (st.empty()) {
				return;
			}
			char tmp = st.top();
			if (a[i] == ')' && tmp == '(') {
				st.pop();
			}
			else if ( a[i] == ']' && tmp == '[') {
				st.pop();
			}
			else {
				 cout << "NO" << endl;
				 return;
			}
		}
	}
	if (st.empty()) cout << "YES";
	else cout << "NO";
}
int main(){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		ct(s);
		cout << endl;
	}
}

